/*
 * demo_twosum.c
 *
 * This demo shows how to use our experimental SQL-inspired hashmap library
 * (SQL_MAP.h / SQL_MAP.c) to solve the classic LeetCode Two Sum problem.
 *
 * We store each number's index as a dynamically allocated int pointer.
 * The keys are the string representations of the numbers.
 * For each number, we look up its complement in the map.
 *
 * Compile with:
 *     gcc demo_twosum.c SQL_MAP.c -o demo_twosum
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SQL_MAP.h"

#define KEY_BUFFER_SIZE 20

int main(void) {
    // Sample input: array of numbers and target value
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(nums) / sizeof(nums[0]);

    // Create our SQL-inspired hashmap.
    SQLMap *map = sql_map_create();

    for (int i = 0; i < n; i++) {
        // Calculate complement for current number.
        int complement = target - nums[i];
        char compKey[KEY_BUFFER_SIZE];
        snprintf(compKey, KEY_BUFFER_SIZE, "%d", complement);

        // Check if the complement exists in the map.
        void *found = sql_map_get(map, compKey);
        if (found != NULL) {
            // Our stored value is a pointer to an int holding the index.
            int *complementIndex = (int *)found;
            printf("Two sum indices found: %d and %d\n", *complementIndex, i);
            sql_map_free(map);
            return EXIT_SUCCESS;
        }

        // Insert the current number into the map.
        // Use its string representation as the key.
        char numKey[KEY_BUFFER_SIZE];
        snprintf(numKey, KEY_BUFFER_SIZE, "%d", nums[i]);
        // Allocate an int on the heap to store the index.
        int *currentIndex = malloc(sizeof(int));
        if (!currentIndex) {
            perror("Failed to allocate memory for currentIndex");
            exit(EXIT_FAILURE);
        }
        *currentIndex = i;
        sql_map_put(map, numKey, currentIndex);
    }

    printf("No two sum solution found.\n");
    sql_map_free(map);
    return EXIT_SUCCESS;
}

