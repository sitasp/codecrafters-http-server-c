

#ifndef CODECRAFTERS_HTTP_SERVER_C_HASHMAP_H
#define CODECRAFTERS_HTTP_SERVER_C_HASHMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry {
    void *key;
    void *value;
    struct entry *next;
} Entry;

typedef struct {
    int size;
    int capacity;
    Entry **buckets;
    size_t key_size;
    size_t value_size;
    int (*key_compare)(void *, void *);
    unsigned int (*key_hash)(void *);
} HashMap;

HashMap *createHashMap(size_t key_size, size_t value_size,
                       int (*key_compare)(void *, void *),
                       unsigned int (*key_hash)(void *));
void insert(HashMap *map, void *key, void *value);
void *get(HashMap *map, void *key);
void resize(HashMap *map);
unsigned int hash(void *key);
int compare(void *a, void *b);

#endif //CODECRAFTERS_HTTP_SERVER_C_HASHMAP_H
