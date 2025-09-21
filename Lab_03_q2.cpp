#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }

};
class Doubly_Queue {
    Node* front;
    Node* last;
public:
    Doubly_Queue(){
        front = nullptr;
        last = nullptr;
    }
    void Enqueue_rear(int value){
        Node* NN = new Node(value);
        if(front == nullptr){
            front = NN;
            last = NN;
        }else if(front == last){
            last = NN;
            front->next = last;
            last->prev = front;
        }else if(front !=last){
            last->next = NN;
            NN->prev = last;
            last = NN;

        }

    }
    void Enqueue_front(int value){
        Node* NN = new Node(value);
        if(front == nullptr){
            front = NN;
            last = NN;  
        }else{
            NN->next = front;
            front->prev = NN;
            front = NN; 
        }
    }
    void Dequeue_front(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        else if(front == last){
            delete front;
            front = nullptr;
            last = nullptr;
        }else{
            Node* del = front;
            front = front->next;
            front->prev = nullptr;
            delete del;
        }
    }
    void Dequeue_rear(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        else if(front == last){
            delete front;
            front = nullptr;
            last = nullptr;
        }else{
            Node* del = last;
            last = last->prev;
            last->next = nullptr;
            delete del;
        }
    }
    bool isempty(){
        return front == nullptr;
    }

    int Peek_front(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else
        return front->data;
    }
    int Peek_rear(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else
        return last->data;
    }
    void display_front(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return;
        }else{
            Node* curr = front;
            while(curr != nullptr){
                cout<<curr->data<<" ";
                curr = curr->next;
            }
        }
    }
    void display_rear(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return;
        }else{
            Node* curr = last;
            while(curr != nullptr){
                cout<<curr->data<<" ";
                curr = curr->prev;
            }
        }
    }

};

int main(){
    Doubly_Queue DQ;
    DQ.Enqueue_rear(10);
    DQ.Enqueue_rear(20);
    DQ.Enqueue_front(5);
    DQ.display_front(); 
    cout<<endl;
    cout<<DQ.Peek_front()<<endl; 
    cout<<DQ.Peek_rear()<<endl;  
    DQ.Dequeue_front();
    cout<<DQ.Peek_front()<<endl; 
    DQ.Dequeue_rear();
    cout<<DQ.Peek_rear()<<endl;  
    return 0;
}