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
class Doubly_list{
    public:
        Node* head;
        Node* tail;

        Doubly_list(int val){
            Node* newNode = new Node(val);
            head = newNode;
            tail = newNode;
        }
        Doubly_list(): head(nullptr), tail(nullptr){}
        
        void insert_at_tail(int value){
            Node* NN = new Node(value);
            if(head == nullptr){
                head = NN;
                tail = NN;  
            }else if(tail == head){
                tail = NN;
                head->next = tail;
                tail->prev = head;  
            }else{
                tail->next = NN;
                NN->prev = tail;
                tail = NN;      
            }
        }
        void insert_at_head(int value){
            Node* NN = new Node(value);
            if(head == nullptr){
                head = NN;
                tail = NN;  
            }else{
                NN->next = head;
                head->prev = NN;
                head = NN; 
            }
        }
        void display(){
            if(head == nullptr){
                cout<<"List is empty"<<endl;
                return;
            }else{
                Node* curr = head;
                while(curr != nullptr){
                    cout<<curr->data<<" ";
                    curr = curr->next;
                }
            }
        }
        void concatenate(Doubly_list &L2){
            if(head == nullptr){
                head = L2.head;
                tail = L2.tail;
            }else if(L2.head == nullptr){
                return;
            }else{
                tail->next = L2.head;
                L2.head->prev = tail;
                tail = L2.tail;
            }
        }      
};
int main(){
    Doubly_list even;
    even.insert_at_tail(2);
    even.insert_at_tail(4);
    even.insert_at_tail(6);
    even.insert_at_tail(8);
    even.insert_at_tail(10);
    cout<<"List 1: ";
    even.display();
    cout<<endl;

    Doubly_list odd;
    odd.insert_at_tail(1);
    odd.insert_at_tail(3);
    odd.insert_at_tail(5);
    odd.insert_at_tail(7);
    odd.insert_at_tail(9);
    cout<<"List 2: ";
    odd.display();
    cout<<endl;

    even.concatenate(odd);
    cout<<"Concatenated List: ";
    even.display();
    cout<<endl;

    return 0;
}