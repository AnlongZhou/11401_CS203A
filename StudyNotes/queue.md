# Data Structure Study Note: Queue

## 1. Definition
A **Queue** is a linear data structure that follows the **FIFO** (First In, First Out) principle. Elements are added at the **Rear** (Tail) and removed from the **Front** (Head).

* **Analogy:** A line of people waiting for a ticket.



## 2. Abstract Data Type (ADT) Operations
* **`enqueue(item)`**: Adds an element to the rear.
* **`dequeue()`**: Removes and returns the element from the front.
* **`front()`**: Returns the first element without removing it.
* **`rear()`**: Returns the last element added.
* **`isEmpty()`**: Checks if the queue is empty.

## 3. Time Complexity
| Operation | Time Complexity | Note |
| :--- | :--- | :--- |
| Enqueue | $O(1)$ | Constant time (with tail pointer). |
| Dequeue | $O(1)$ | Constant time (with head pointer). |
| Front/Peek | $O(1)$ | Constant time. |

## 4. C++ Implementation Snippet (Linked List-based)
```cpp
struct Node { int data; Node* next; };
// Enqueue adds to rear, Dequeue removes from front
void enqueue(Node*& rear, int val) {
    Node* temp = new Node{val, nullptr};
    rear->next = temp;
    rear = temp;
}
