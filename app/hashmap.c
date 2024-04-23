#include "headers/hashmap.h"

#define MAX_CAPACITY 100000

HashMap *createHashMap(size_t key_size, size_t value_size,
                       int (*key_compare)(void *, void *),
                       unsigned int (*key_hash)(void *)) {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    if (map == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    map->size = 0;
    map->capacity = MAX_CAPACITY; // Initial capacity
    map->buckets = (Entry **)calloc(map->capacity, sizeof(Entry *));
    if (map->buckets == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    map->key_size = key_size;
    map->value_size = value_size;
    map->key_compare = key_compare;
    map->key_hash = key_hash;
    return map;
}

void insert(HashMap *map, void *key, void *value) {
    if (map == NULL || key == NULL) return;

    // Resize if necessary
    if (map->size >= map->capacity * 0.75) {
        resize(map);
    }

    // Calculate hash
    unsigned int index = map->key_hash(key) % map->capacity;

    // Create new entry
    Entry *newEntry = (Entry *)malloc(sizeof(Entry));
    if (newEntry == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newEntry->key = malloc(map->key_size);
    newEntry->value = malloc(map->value_size);
    if (newEntry->key == NULL || newEntry->value == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    memcpy(newEntry->key, key, map->key_size);
    memcpy(newEntry->value, value, map->value_size);
    newEntry->next = NULL;

    // Insert into the bucket
    if (map->buckets[index] == NULL) {
        map->buckets[index] = newEntry;
    } else {
        Entry *current = map->buckets[index];
        while (current->next != NULL) {
            current = (Entry *) current->next;
        }
        current->next = (struct entry *) newEntry;
    }

    map->size++;
}

void *get(HashMap *map, void *key) {
    if (map == NULL || key == NULL) return NULL;

    // Calculate hash
    unsigned int index = map->key_hash(key) % map->capacity;

    // Search for the key in the bucket
    Entry *current = map->buckets[index];
    while (current != NULL) {
        if (map->key_compare(current->key, key) == 0) {
            return current->value;
        }
        current = (Entry *) current->next;
    }

    return NULL; // Key not found
}

void resize(HashMap *map) {
    int newCapacity = map->capacity * 2;
    Entry **newBuckets = (Entry **)calloc(newCapacity, sizeof(Entry *));
    if (newBuckets == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Rehash all entries
    for (int i = 0; i < map->capacity; i++) {
        Entry *current = map->buckets[i];
        while (current != NULL) {
            Entry *next = (Entry *) current->next;
            unsigned int newIndex = map->key_hash(current->key) % newCapacity;
            current->next = (struct entry *) newBuckets[newIndex];
            newBuckets[newIndex] = current;
            current = next;
        }
    }

    // Update capacity and bucket array
    free(map->buckets);
    map->buckets = newBuckets;
    map->capacity = newCapacity;
}

unsigned int hash(void *key) {
    // Example hash function for integers
    return *(int *)key;
}

int compare(void *a, void *b) {
    // Example compare function for integers
    int keyA = *(int *)a;
    int keyB = *(int *)b;
    return keyA - keyB;
}
