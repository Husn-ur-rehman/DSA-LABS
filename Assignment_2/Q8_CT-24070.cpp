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
class Queue {
    public:
        Node* front;
        Node* rear;
        int size;
        Queue() {
            front = NULL;
            rear = NULL;
            size = 0;
        }
        void enqueue(int val) {
            Node* newNode = new Node(val);
            if (rear == NULL) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }
        void dequeue() {
            if (front == NULL) {
                cout << "Queue is empty" << endl;
                return;
            }
            Node* temp = front;
            front = front->next;
            if (front == NULL) {
                rear = NULL;
            }
            delete temp;
            size--;
        }
        int peek() {
            if (front == NULL) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            return front->data;
        }
        bool isEmpty() {
            return size == 0;
        }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout <<q.peek() << endl; 
    q.dequeue();
    cout << q.peek() << endl; 
    q.dequeue();
    q.dequeue();
    cout <<q.isEmpty()<< endl;
    return 0;
}