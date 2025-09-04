#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define NUM_KEYS 15

long long hashSet[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashSet[i] = -1;
    }
}

int hashFunction(int key) {
    return (key % 18) + 2;
}

int exists(long long val) {
    for (int i = 0; i < SIZE; i++) {
        if (hashSet[i] == val)
            return 1;
    }
    return 0;
}

void add(int key) {
    int index = hashFunction(key);

    for (int prob = 0; prob < SIZE; prob++) {
        int newIndex = (index + prob) % SIZE;

        if (hashSet[newIndex] == -1) {
            hashSet[newIndex] = key;
            return;
        }
        if (hashSet[newIndex] == key) {
            printf("%d already exists.\n", key);
            return;
        }
    }

    printf("Hash Set is Full. Could not insert %d\n", key);
}

void display() {
    printf("\nFinal Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashSet[i] != -1)
            printf("Index %2d: %lld\n", i, hashSet[i]);
        else
            printf("Index %2d: EMPTY\n", i);
    }
}

int main() {
    srand(time(NULL));
    initialize();

    int inserted = 0;
    while (inserted < NUM_KEYS) {
        int num = (rand() % 900000) + 100000;

        if (!exists(num)) {
            add(num);
            inserted++;
        }
    }

    display();
    return 0;
}
