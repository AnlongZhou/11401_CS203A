#include <iostream>
using namespace std;
// ==========================================
// Stack (Array-based Implementation)
// ==========================================
class Stack {
  private:
    int top;
    int capacity;
    int *array;

  public:
    Stack(int size) {
        capacity = size;
        array = new int[capacity];
        top = -1;
    }

    ~Stack() { delete[] array; }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        array[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return array[top--];
    }

    int peek() {
        if (isEmpty())
            return -1;
        return array[top];
    }

    bool isEmpty() { return top == -1; }
};
