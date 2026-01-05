# Data Structure Study Note: Binary Search Tree (BST)

## 1. Definition
A **Binary Search Tree** is a hierarchical structure where every node has at most two children. It maintains the **BST Property**:
1.  **Left Subtree:** All values are *less* than the root.
2.  **Right Subtree:** All values are *greater* than the root.



<img width="1200" height="1000" alt="Image" src="https://github.com/user-attachments/assets/e6022956-81c4-4a78-8c8f-0cb48e798e2c" />


## 2. Abstract Data Type (ADT) Operations
* **`insert(key)`**: Places a new node in the correct sorted location.
* **`search(key)`**: Traverses left or right based on value comparison.
* **`delete(key)`**: Removes a node. (Complex: involves handling children replacement).
* **`traverse()`**: Visits nodes (In-order traversal yields sorted values).

## 3. Time Complexity
| Operation | Average | Worst | Note |
| :--- | :--- | :--- | :--- |
| Search | $O(\log n)$ | $O(n)$ | Worst case is a "skewed" tree (like a linked list). |
| Insert | $O(\log n)$ | $O(n)$ | Depends on tree height ($h$). |
| Delete | $O(\log n)$ | $O(n)$ | Depends on tree height ($h$). |

## 4. C++ Implementation Snippet
```cpp
struct Node { int data; Node *left, *right; };

Node* insert(Node* node, int val) {
    if(!node) return new Node{val, nullptr, nullptr};
    if(val < node->data) node->left = insert(node->left, val);
    else node->right = insert(node->right, val);
    return node;
}
