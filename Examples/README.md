# Data Structures Reference Guide

## 1. Linked List
**Definition:** A linear data structure where elements (nodes) are distinct objects stored in non-contiguous memory. Each node contains data and a reference (pointer) to the next node.

### Structure
* **Node:** Contains `Data` and `Next` pointer.
* **Head:** Reference to the first node.

### Abstract Data Type (ADT)
* `head`: Reference to the first node.
* `insert(data)`: Adds a new node (commonly at head or tail).
* `delete(key)`: Removes the first node containing the key.
* `search(key)`: Finds a node containing the key.
* `isEmpty()`: Returns true if the list contains no nodes.

### Time Complexity (Singly Linked)
| Operation | Average | Worst |
| :--- | :--- | :--- |
| Access | $O(n)$ | $O(n)$ |
| Search | $O(n)$ | $O(n)$ |
| Insertion (at head) | $O(1)$ | $O(1)$ |
| Deletion (at head) | $O(1)$ | $O(1)$ |

---

## 2. Stack
**Definition:** A linear data structure that follows the **LIFO** (Last In, First Out) principle. Elements are added and removed from the same end, called the "top".

### Structure
* **Top:** The index or pointer to the most recently added element.

### Abstract Data Type (ADT)
* `push(item)`: Adds an item to the top of the stack.
* `pop()`: Removes the item from the top of the stack.
* `peek()` (or `top()`): Returns the item at the top without removing it.
* `isEmpty()`: Returns true if the stack is empty.

### Time Complexity
| Operation | Average | Worst |
| :--- | :--- | :--- |
| Access | $O(n)$ | $O(n)$ |
| Search | $O(n)$ | $O(n)$ |
| Push | $O(1)$ | $O(1)$ |
| Pop | $O(1)$ | $O(1)$ |

---

## 3. Queue
**Definition:** A linear data structure that follows the **FIFO** (First In, First Out) principle. Elements are added at the "rear" and removed from the "front".

### Structure
* **Front (Head):** Where items are removed.
* **Rear (Tail):** Where items are added.

### Abstract Data Type (ADT)
* `enqueue(item)`: Adds an item to the rear of the queue.
* `dequeue()`: Removes the item from the front of the queue.
* `front()` (or `peek()`): Returns the item at the front without removing it.
* `isEmpty()`: Returns true if the queue is empty.

### Time Complexity
| Operation | Average | Worst |
| :--- | :--- | :--- |
| Access | $O(n)$ | $O(n)$ |
| Search | $O(n)$ | $O(n)$ |
| Enqueue | $O(1)$ | $O(1)$ |
| Dequeue | $O(1)$ | $O(1)$ |

---

## 4. Binary Search Tree (BST)
**Definition:** A hierarchical structure where each node has at most two children. It maintains a specific order: the left child is always less than the parent, and the right child is always greater than the parent.

### Structure
* **Root:** Topmost node.
* **Left Child:** Value < Parent.
* **Right Child:** Value > Parent.

### Abstract Data Type (ADT)
* `insert(key)`: Adds a new key in the correct sorted position.
* `search(key)`: Traverses the tree to find the key.
* `delete(key)`: Removes a key and restructures the tree to maintain BST properties.
* `traverse()`: Visits all nodes (In-order, Pre-order, Post-order).
* `findMin()` / `findMax()`: Finds the smallest or largest value.

### Time Complexity
| Operation | Average | Worst (Unbalanced) |
| :--- | :--- | :--- |
| Search | $O(\log n)$ | $O(n)$ |
| Insertion | $O(\log n)$ | $O(n)$ |
| Deletion | $O(\log n)$ | $O(n)$ |

---

## 5. Hash Table
**Definition:** A data structure that maps keys to values using a **hash function**. It is designed for very fast lookups. The hash function computes an index into an array of buckets/slots.

### Structure
* **Buckets/Slots:** The array storage.
* **Hash Function:** Converts key to index.
* **Collision Resolution:** Chaining (Linked Lists) or Open Addressing.

### Abstract Data Type (ADT)
* `put(key, value)`: Hashes the key and adds the pair to the table.
* `get(key)`: Returns the value associated with the key.
* `remove(key)`: Deletes the key-value pair.
* `containsKey(key)`: Checks if the key exists in the table.

### Time Complexity
| Operation | Average | Worst (Many Collisions) |
| :--- | :--- | :--- |
| Search | $O(1)$ | $O(n)$ |
| Insertion | $O(1)$ | $O(n)$ |
| Deletion | $O(1)$ | $O(n)$ |
