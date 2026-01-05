# Data Structure Study Note: Linked List

## 1. Definition
A **Linked List** is a linear data structure where elements (nodes) are not stored in contiguous memory locations. Instead, each node links to the next node using a pointer.

* **Node Structure:** Contains `Data` (the value) and `Next` (address of the next node).
* **Head:** A pointer to the first node in the list.
* **Types:** Singly Linked, Doubly Linked (pointers to next and previous), Circular.



## 2. Abstract Data Type (ADT) Operations
* **`insert(data)`**: Adds a new node to the list (Head, Tail, or specific index).
* **`delete(key)`**: Removes the node containing the specific data.
* **`search(key)`**: Traverses the list to find if a value exists.
* **`isEmpty()`**: Returns `true` if `head` is `null`.
* **`size()`**: Returns the count of nodes.

## 3. Time Complexity
| Operation | Average Case | Worst Case | Note |
| :--- | :--- | :--- | :--- |
| Access/Search | $O(n)$ | $O(n)$ | Sequential access only. |
| Insert (at Head) | $O(1)$ | $O(1)$ | Just update the head pointer. |
| Insert (at Tail) | $O(n)$ | $O(n)$ | Must traverse to end (unless tail pointer exists). |
| Delete (at Head) | $O(1)$ | $O(1)$ | Update head to `head->next`. |

## 4. C++ Implementation Snippet
```cpp
struct Node {
    int data;
    Node* next;
};

void insertHead(Node*& head, int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
}
