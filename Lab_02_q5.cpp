#include<bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
class CircularQueue{
    Node* front;
    Node* rear;
    int size;
    int capacity;
    public:
    CircularQueue(int cap) {    
        front = NULL;
        rear = NULL;
        size = 0;
        capacity = cap;
    }
    bool isFull() {
        return size == capacity;
    }
    bool isEmpty() {
        return size == 0;
    }
    void enqueue(int val) {
        if(isFull()) {
            cout << "Queue is full\n";
            return;
        }
        Node* newNode = new Node(val);
        if(isEmpty()) {
            front = newNode;
            rear = newNode;
            newNode->next = front; // Point to itself
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Maintain circular link
        }
        size++;
    }
    void dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        if(front == rear) { // Only one element
            front = NULL;
            rear = NULL;
        } else {
            front = front->next;
            rear->next = front; // Maintain circular link
        }
        delete temp;
        size--;
    }
    int peek() {
        if(isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
};

int main() {
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout << "Front element: " << cq.peek() << endl; // 10
    cq.dequeue();
    cout << "Front element after dequeue: " << cq.peek() << endl; // 20
    return 0;
    
}