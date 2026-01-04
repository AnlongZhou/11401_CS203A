#include <iostream>
using namespace std;

// ==========================================
// Linked List (Singly Linked)
// ==========================================
struct ListNode {
    int data;
    ListNode *next;

    ListNode(int val) : data(val), next(nullptr) {}
};

class LinkedList {
  private:
    ListNode *head;

  public:
    LinkedList() : head(nullptr) {}

    // Insert at the end
    void append(int data) {
        ListNode *newNode = new ListNode(data);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete first occurrence of value
    void remove(int data) {
        if (!head)
            return;

        if (head->data == data) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode *current = head;
        while (current->next && current->next->data != data) {
            current = current->next;
        }

        if (current->next) {
            ListNode *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void display() {
        ListNode *temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};








