#include <stdio.h>

#include <stdlib.h> 
int main() {

    int* array; 
    int size = 0;
    int input;

    printf("Enter integers (press any non-integer key to stop):\n");

    while (scanf("%d", &input) == 1) {

        // Increase the size of the array by 1

        size++;

        // Reallocate memory for the array with the updated size 
        array = realloc(array, size*sizeof(int));

        // Assign the input value to the last element of the array 
        array[size-1] = input;
    }
    int count=0;

    for (int i = 0; i < size; i++){
        count+=array[i];
    }
    printf("The sum of all the elements in the array are :-\t\t%d \n average of all the elements in the array are :-\t%f",count, (float)count/size);

    // Free the allocated memory

    free(array);

    return 0;
}