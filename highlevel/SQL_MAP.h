#ifndef SQL_MAP_H
#define SQL_MAP_H

#include <stddef.h>

// Experimental SQL-like hashmap in C
// The index node holds a string key and a pointer to an integer representing
// the index of the corresponding data in the data array.

typedef struct IndexNode {
    char *key;
    int *dataIndex;  // pointer to index in data array
} IndexNode;

typedef struct DataNode {
    void *data;
} DataNode;

typedef struct SQLMap {
    IndexNode **indexNodes;  // hash table array of pointers (using open addressing)
    size_t indexCapacity;     // capacity of indexNodes array (a prime number is recommended)
    // Data array to hold arbitrary data pointers:
    DataNode *dataNodes;
    size_t dataCapacity;      // capacity of dataNodes array
    size_t dataCount;         // current number of data nodes
} SQLMap;

// Create a new SQLMap instance.
SQLMap* sql_map_create(void);

// Insert or update a key-value pair in the SQLMap.
void sql_map_put(SQLMap *map, const char *key, void *value);

// Retrieve the value associated with the given key. Returns NULL if not found.
void* sql_map_get(SQLMap *map, const char *key);

// Free all memory associated with the SQLMap.
void sql_map_free(SQLMap *map);

#endif  // SQL_MAP_H



