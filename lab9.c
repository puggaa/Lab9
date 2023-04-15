// Andrew Ang
//COP 3502C Lab
//Assignmennt 9

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

struct RecordType
{
    int id;
    char name;
    int order;
};

struct Node {
    struct RecordType data;
    struct Node *next;
};

// Hash table
struct HashTable {
    struct Node *table[TABLE_SIZE];
};

int hash(int x)
{
    return x % TABLE_SIZE;
}

void insert(struct HashTable *hashTable, struct RecordType record)
{
    int index = hash(record.id);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed");
        return;
    }
    newNode->data = record;
    newNode->next = NULL;

    if (hashTable->table[index] == NULL) {
     
        hashTable->table[index] = newNode;
    } else {
        
        struct Node *current = hashTable->table[index];
        
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Prints all records in the hash table
void printHashTable(struct HashTable *hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d:\n", i);
        struct Node *current = hashTable->table[i];
        while (current != NULL) {
            printf("\t%d %c %d\n", current->data.id, current->data.name, current->data.order);
            current = current->next;
        }
    }
}

int main(void)
{
    struct HashTable hashTable;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable.table[i] = NULL;
    }

    struct RecordType records[] = {
        {1, 'A', 2},
        {2, 'B', 3},
        {101, 'C', 4},
        {102, 'D', 5},
        {103, 'E', 6},
        {201, 'F', 7},
        {202, 'G', 8},
        {301, 'H', 9},
        {401, 'I', 10}
    };
    int numRecords = sizeof(records) / sizeof(records[0]);

    // Insert all records into the hash table
    for (int i = 0; i < numRecords; i++) {
        insert(&hashTable, records[i]);
    }

    // Print all records in the hash table
    printHashTable(&hashTable);

    return 0;
}