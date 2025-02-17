#include "SQL_MAP.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// A simple hash function (djb2 by Dan Bernstein)
static unsigned long hash_str(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

// Initial capacities: choose a prime for the index table.
#define INITIAL_INDEX_CAPACITY 10007
#define INITIAL_DATA_CAPACITY 16

// Helper to duplicate a string (since strdup is not in standard C)
static char* str_duplicate(const char *src) {
    size_t len = strlen(src);
    char *dst = malloc(len + 1);
    if (dst) {
        strcpy(dst, src);
    }
    return dst;
}

// Create a new SQLMap instance.
SQLMap* sql_map_create(void) {
    SQLMap *map = malloc(sizeof(SQLMap));
    if (!map) {
        perror("Failed to allocate SQLMap");
        exit(EXIT_FAILURE);
    }
    map->indexCapacity = INITIAL_INDEX_CAPACITY;
    map->indexNodes = calloc(map->indexCapacity, sizeof(IndexNode*));
    if (!map->indexNodes) {
        perror("Failed to allocate indexNodes");
        free(map);
        exit(EXIT_FAILURE);
    }
    map->dataCapacity = INITIAL_DATA_CAPACITY;
    map->dataCount = 0;
    map->dataNodes = malloc(map->dataCapacity * sizeof(DataNode));
    if (!map->dataNodes) {
        perror("Failed to allocate dataNodes");
        free(map->indexNodes);
        free(map);
        exit(EXIT_FAILURE);
    }
    return map;
}

// Expand the dataNodes array when full.
static void expand_data_nodes(SQLMap *map) {
    map->dataCapacity *= 2;
    map->dataNodes = realloc(map->dataNodes, map->dataCapacity * sizeof(DataNode));
    if (!map->dataNodes) {
        perror("Failed to expand dataNodes");
        exit(EXIT_FAILURE);
    }
}

// Insert or update a key-value pair.
void sql_map_put(SQLMap *map, const char *key, void *value) {
    // First, insert the data into the dataNodes array.
    if (map->dataCount >= map->dataCapacity) {
        expand_data_nodes(map);
    }
    int dataIndexValue = (int)map->dataCount;
    map->dataNodes[map->dataCount].data = value;
    map->dataCount++;

    // Create a new int on the heap to store the index.
    int *dataIndexPtr = malloc(sizeof(int));
    if (!dataIndexPtr) {
        perror("Failed to allocate data index pointer");
        exit(EXIT_FAILURE);
    }
    *dataIndexPtr = dataIndexValue;

    // Prepare the new index node.
    IndexNode *newIndexNode = malloc(sizeof(IndexNode));
    if (!newIndexNode) {
        perror("Failed to allocate IndexNode");
        exit(EXIT_FAILURE);
    }
    newIndexNode->key = str_duplicate(key);
    newIndexNode->dataIndex = dataIndexPtr;

    // Now insert into the indexNodes hash table using open addressing (linear probing).
    unsigned long hashVal = hash_str(key);
    size_t pos = hashVal % map->indexCapacity;
    while (map->indexNodes[pos] != NULL) {
        // If the key already exists, update the data pointer in the data array.
        if (strcmp(map->indexNodes[pos]->key, key) == 0) {
            // Free the old data index pointer and key, then update.
            free(map->indexNodes[pos]->dataIndex);
            free(map->indexNodes[pos]->key);
            map->indexNodes[pos]->dataIndex = newIndexNode->dataIndex;
            // Free the temporary new index node.
            free(newIndexNode);
            return;
        }
        pos = (pos + 1) % map->indexCapacity;
    }
    map->indexNodes[pos] = newIndexNode;
}

// Retrieve the value associated with a key.
void* sql_map_get(SQLMap *map, const char *key) {
    unsigned long hashVal = hash_str(key);
    size_t pos = hashVal % map->indexCapacity;
    size_t startPos = pos;
    while (map->indexNodes[pos] != NULL) {
        if (strcmp(map->indexNodes[pos]->key, key) == 0) {
            int dataIndex = *(map->indexNodes[pos]->dataIndex);
            assert(dataIndex < (int)map->dataCount);
            return map->dataNodes[dataIndex].data;
        }
        pos = (pos + 1) % map->indexCapacity;
        if (pos == startPos) break;  // full cycle
    }
    return NULL;
}

// Free all allocated memory.
void sql_map_free(SQLMap *map) {
    // Free index nodes.
    for (size_t i = 0; i < map->indexCapacity; i++) {
        if (map->indexNodes[i]) {
            free(map->indexNodes[i]->dataIndex);
            free(map->indexNodes[i]->key);
            free(map->indexNodes[i]);
        }
    }
    free(map->indexNodes);
    // Free data nodes.
    // (Note: freeing the stored data itself is the caller's responsibility.)
    free(map->dataNodes);
    free(map);
}

