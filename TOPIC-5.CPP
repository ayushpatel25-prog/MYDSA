// INTRODUCTION TO DEQUE USING DOUBLY LINKLIST
// HERE WE CAN ADD AT FRONT AS WELL AS ADD AT END AND VICE VERSA FOR DELETE OPERATION
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class Deque {
public:
    Node* head;
    Node* tail;
    int size;

    Deque() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Insert at front
    void pushFront(int val) {
        Node* temp = new Node(val);

        if (size == 0) {
            head = tail = temp;
        }
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        size++;
    }

    // Insert at back
    void pushBack(int val) {
        Node* temp = new Node(val);

        if (size == 0) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        size++;
    }

    // Delete from front
    void popFront() {
        if (size == 0) {
            cout << "Deque is empty" << endl;
            return;
        }

        Node* temp = head;

        if (size == 1) {
            head = tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
        size--;
    }

    // Delete from back
    void popBack() {
        if (size == 0) {
            cout << "Deque is empty" << endl;
            return;
        }

        Node* temp = tail;

        if (size == 1) {
            head = tail = NULL;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
        size--;
    }

    // Get front element
    int getFront() {
        if (size == 0) {
            cout << "Deque is empty" << endl;
            return -1;
        }

        return head->val;
    }

    // Get back element
    int getBack() {
        if (size == 0) {
            cout << "Deque is empty" << endl;
            return -1;
        }

        return tail->val;
    }

    // Display
    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Deque q;

    q.pushBack(10);
    q.pushBack(20);
    q.pushFront(5);
    q.pushFront(2);

    q.display();

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.getBack() << endl;

    q.popFront();
    q.display();

    q.popBack();
    q.display();

    return 0;
}

