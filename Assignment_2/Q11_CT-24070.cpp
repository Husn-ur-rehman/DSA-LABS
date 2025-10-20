#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }

};
class Deque{
    Node* front;
    Node* rear;
    int sz;
    public:
    Deque(){
        front = NULL;
        rear = NULL;
        sz = 0;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(front == NULL){
            front = newNode;
            rear = newNode;
        }
        else{
            newNode->next = front;
            front = newNode;
        }
        sz++;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(rear == NULL){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        sz++;
    }
    void pop_front(){
        if(front == NULL){
            cout<<"Deque is empty"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        sz--;
        if(front == NULL){
            rear = NULL;
        }
    }
    void pop_back(){
        if(rear == NULL){
            cout<<"Deque is empty"<<endl;
            return;
        }
        if(front == rear){
            delete rear;
            front = NULL;
            rear = NULL;
        }
        else{
            Node* temp = front;
            while(temp->next != rear){
                temp = temp->next;
            }
            delete rear;
            rear = temp;
            rear->next = NULL;
        }
        sz--;
    }
    int getFront(){
        if(front == NULL){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        return front->data;
    }
    int getRear(){
        if(rear == NULL){
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        return rear->data;
    }
    bool empty(){
        return sz == 0;
    }
    int size(){
        return sz;
    }
    int minimumoperations(){
        return sz;
        while(!empty())
            pop_front();
    }
};
int main(){
    Deque dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    cout<<dq.minimumoperations()<<endl;

    return 0;
}