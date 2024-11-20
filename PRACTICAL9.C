#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
struct Node {
    int key;
    struct Node* next;
};

struct HashTable {
    int *table;
    int *status;  
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

int hashFunction1(int key) {
    return key % TABLE_SIZE;
}

int hashFunction2(int key) {
    double A = 0.6180339887;  
    double temp = key * A;
    return (int)(TABLE_SIZE * (temp - (int)temp));
}

void insertChaining(struct Node* hashTable[], int key) {
    int index = hashFunction1(key);
    struct Node* newNode = createNode(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int searchChaining(struct Node* hashTable[], int key) {
    int index = hashFunction1(key);
    struct Node* temp = hashTable[index];
    while (temp) {
        if (temp->key == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void initHashTable(struct HashTable* ht) {
    ht->table = (int*)malloc(sizeof(int) * TABLE_SIZE);
    ht->status = (int*)malloc(sizeof(int) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = -1;  
        ht->status[i] = 0;  
    }
}

void insertOpenAddressing(struct HashTable* ht, int key) {
    int index = hashFunction1(key);
    int i = 0;
    while (i < TABLE_SIZE) {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (ht->status[probeIndex] == 0 || ht->status[probeIndex] == 2) {  
            ht->table[probeIndex] = key;
            ht->status[probeIndex] = 1; 
            return;
        }
        i++;
    }
    printf("Hash table is full\n");
}

int searchOpenAddressing(struct HashTable* ht, int key) {
    int index = hashFunction1(key);
    int i = 0;
    while (i < TABLE_SIZE) {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (ht->status[probeIndex] == 0) {
            return 0;  
        }
        if (ht->status[probeIndex] == 1 && ht->table[probeIndex] == key) {
            return 1;  
        }
        i++;
    }
    return 0;
}

void displayChaining(struct Node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == NULL) {
            printf("Index %d: Empty\n", i);
        } else {
            printf("Index %d: ", i);
            struct Node* temp = hashTable[i];
            while (temp) {
                printf("%d -> ", temp->key);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

void displayOpenAddressing(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->status[i] == 0) {
            printf("Index %d: Empty\n", i);
        } else if (ht->status[i] == 1) {
            printf("Index %d: %d\n", i, ht->table[i]);
        } else {
            printf("Index %d: Deleted\n", i);
        }
    }
}

int main() {
    struct Node* hashTableChaining[TABLE_SIZE] = {0}; 
    insertChaining(hashTableChaining, 15);
    insertChaining(hashTableChaining, 25);
    insertChaining(hashTableChaining, 35);
    insertChaining(hashTableChaining, 5);
    
    printf("Chaining Method Hash Table:\n");
    displayChaining(hashTableChaining);

    printf("Searching for key 25: %s\n", searchChaining(hashTableChaining, 25) ? "Found" : "Not Found");

    struct HashTable ht;
    initHashTable(&ht);
    insertOpenAddressing(&ht, 15);
    insertOpenAddressing(&ht, 25);
    insertOpenAddressing(&ht, 35);
    insertOpenAddressing(&ht, 5);

    printf("\nOpen Addressing Hash Table:\n");
    displayOpenAddressing(&ht);
    printf("Searching for key 25: %s\n", searchOpenAddressing(&ht, 25) ? "Found" : "Not Found");

    return 0;
}

