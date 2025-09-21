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
        void sort_descend(){
            if(head == nullptr || head->next == nullptr){
                return;
            }
            bool swapped;
            do{
                swapped = false;
                Node* curr = head;
                while(curr->next != nullptr){
                    if(curr->data < curr->next->data){
                        swap(curr->data, curr->next->data);
                        swapped = true;
                    }
                    curr = curr->next;
                }
            }while(swapped);
        }     
};
int main(){
    Doubly_list L1;
    L1.insert_at_tail(1);
    L1.insert_at_tail(3);
    L1.insert_at_tail(5);
    L1.insert_at_tail(9);
    cout<<"List 1: ";
    L1.display();
    cout<<endl;

    Doubly_list L2;
    L2.insert_at_tail(2);
    L2.insert_at_tail(4);
    L2.insert_at_tail(6);
    L2.insert_at_tail(8);
    L2.insert_at_tail(10);
    cout<<"List 2: ";
    L2.display();
    cout<<endl;

    L1.concatenate(L2);
    cout<<"Concatenated List: ";
    L1.display();
    cout<<endl;

    L1.sort_descend();
    cout<<"Sorted List in Descending Order: ";
    L1.display();
    cout<<endl;

    return 0;
}