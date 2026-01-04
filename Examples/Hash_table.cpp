#include <iostream>
using namespace std;

// ==========================================
// Hash Table (Chaining with Linked List)
// ==========================================
class HashTable {
  private:
    struct HashNode {
        int key;
        int value;
        HashNode *next;
        HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    HashNode **table;
    int size;

    int hashFunction(int key) { return key % size; }

  public:
    HashTable(int tableSize) {
        size = tableSize;
        table = new HashNode *[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            HashNode *entry = table[i];
            while (entry) {
                HashNode *prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }

    void insert(int key, int value) {
        int hashIndex = hashFunction(key);
        HashNode *prev = nullptr;
        HashNode *entry = table[hashIndex];

        while (entry && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (!entry) {
            // Key not found, create new
            entry = new HashNode(key, value);
            if (!prev) {
                // Insert as first element in bucket
                table[hashIndex] = entry;
            } else {
                // Insert at end of chain
                prev->next = entry;
            }
        } else {
            // Key exists, update value
            entry->value = value;
        }
    }

    int search(int key) {
        int hashIndex = hashFunction(key);
        HashNode *entry = table[hashIndex];
        while (entry) {
            if (entry->key == key)
                return entry->value;
            entry = entry->next;
        }
        return -1; // Not found
    }
};
