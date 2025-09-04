#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

typedef struct {
    int key;
    char value[50];
    int isOccupied;
} DictionaryEntry;

DictionaryEntry hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].isOccupied = 0;
    }
}

void insert(int key, const char *value) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index].isOccupied) {
        if (hashTable[index].key == key) {
            strcpy(hashTable[index].value, value);
            printf("Updated key %d with new value \"%s\".\n", key, value);
            return;
        }
        index = (originalIndex + ++i) % SIZE;
        if (index == originalIndex) {
            printf("Hash table full! Cannot insert key %d.\n", key);
            return;
        }
    }

    hashTable[index].key = key;
    strcpy(hashTable[index].value, value);
    hashTable[index].isOccupied = 1;
    printf("Inserted key %d with value \"%s\" at index %d.\n", key, value, index);
}

char* search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index].isOccupied) {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = (originalIndex + ++i) % SIZE;
        if (index == originalIndex) {
            break; 
        }
    }

    return NULL; 
}

void display() {
    printf("\nDictionary contents:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i].isOccupied) {
            printf("Index %2d: Key = %d, Value = %s\n", i, hashTable[i].key, hashTable[i].value);
        }
    }
}

int main() {
    initialize();

    insert(1, "Apple");
    insert(21, "Banana");
    insert(41, "Cherry");
    insert(61, "Date");
    insert(2, "Elderberry");

    display();

    int keyToSearch = 21;
    char *result = search(keyToSearch);
    if (result) {
        printf("\nValue found for key %d: %s\n", keyToSearch, result);
    } else {
        printf("\nKey %d not found in dictionary.\n", keyToSearch);
    }

    return 0;
}
