#include<bits/stdc++.h>
using namespace std;    
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class Circular_Queue{
    Node* front;
    Node* last;
    public:
        Circular_Queue(){
            front = nullptr;
            last = nullptr;
        }
        void Enqueue(int val){
            Node* NN = new Node(val);
            if(front == nullptr){
                front = NN;
                last = NN;
                last->next = front; // for circular
            }else{  
                last->next = NN;
                last = NN;
                last->next = front; 
            }

        } 
        void Dequeue(){
            if(front == nullptr){
                cout<<"Queue is empty"<<endl;
                return;
            }
            else if(front == last){
                delete front;
                front = nullptr;
                last = nullptr;

            }
            else{
                Node* del = front;
                front = front->next;
                last->next = front;
                delete del;

            }
        }
        bool isEmpty(){
            return front == nullptr;
        }   
        int peek(){
            if(front == nullptr){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return front->data;
        }
        void display(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return;
            }else{
                Node* curr = front;
                while(curr->next != front){
                    cout<<curr->data<<" ";
                    curr = curr->next;
                }
                cout<<curr->data<<" ";
            }
        }

};
int main(){
    Circular_Queue QQ;
    QQ.Enqueue(45);
    QQ.Enqueue(55);
    QQ.Enqueue(56);
    QQ.display();
    cout<<endl;
    cout<<QQ.peek()<<endl;
    QQ.Dequeue();
    QQ.display();
    cout<<endl;
    cout<<QQ.peek()<<endl;
    return 0;
}