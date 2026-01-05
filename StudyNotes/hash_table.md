# Data Structure Study Note: Hash Table

## 1. Definition
A **Hash Table** (or Hash Map) is a structure that maps **keys** to **values** for highly efficient lookups. It uses a **Hash Function** to compute an index into an array of "buckets".

* **Hash Function:** $Index = hash(Key) \% ArraySize$
* **Collision:** When two keys hash to the same index.
    * *Chaining:* Store a linked list at each index.
    * *Open Addressing:* Find the next empty slot (Linear Probing).



## 2. Abstract Data Type (ADT) Operations
* **`put(key, value)`**: Hashes key and stores value.
* **`get(key)`**: Returns value associated with key.
* **`remove(key)`**: Deletes the key-value pair.
* **`containsKey(key)`**: Boolean check for existence.

## 3. Time Complexity
| Operation | Average | Worst | Note |
| :--- | :--- | :--- | :--- |
| Insert | $O(1)$ | $O(n)$ | Worst case happens if many collisions occur. |
| Search | $O(1)$ | $O(n)$ | Relies on a good uniform hash function. |
| Delete | $O(1)$ | $O(n)$ | Same as search. |

## 4. C++ Implementation Snippet (Chaining)
```cpp
list<pair<int, int>> table[10]; // Array of lists
void insert(int key, int val) {
    int index = key % 10;
    table[index].push_back({key, val});
}
