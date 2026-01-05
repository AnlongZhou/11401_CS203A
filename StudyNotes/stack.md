# Data Structure Study Note: Stack

## 1. Definition
A **Stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle. Elements are inserted and removed from the same end, known as the **Top**.

* **Analogy:** A stack of plates. You can only take the top plate off.



## 2. Abstract Data Type (ADT) Operations
* **`push(item)`**: Adds an element to the top of the stack.
* **`pop()`**: Removes and returns the top element.
* **`peek()` / `top()`**: Returns the top element without removing it.
* **`isEmpty()`**: Checks if the stack has no elements.
* **`isFull()`**: Checks if the stack has reached capacity (for array-based implementation).

## 3. Time Complexity
| Operation | Time Complexity | Note |
| :--- | :--- | :--- |
| Push | $O(1)$ | Constant time. |
| Pop | $O(1)$ | Constant time. |
| Peek | $O(1)$ | Constant time. |
| Search | $O(n)$ | Must pop elements to reach the bottom. |

## 4. C++ Implementation Snippet (Array-based)
```cpp
class Stack {
    int top = -1;
    int arr[100];
public:
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
};
