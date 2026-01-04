#include <iostream>
using namespace std;

// ==========================================
// Queue (Linked List-based Implementation)
// ==========================================
struct QNode {
    int data;
    QNode *next;
    QNode(int d) : data(d), next(nullptr) {}
};

class Queue {
  private:
    QNode *front, *rear;

  public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int data) {
        QNode *newNode = new QNode(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (front == nullptr)
            return -1;

        QNode *temp = front;
        int data = temp->data;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        return data;
    }

    bool isEmpty() { return front == nullptr; }
};
