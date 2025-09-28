#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int value):data(value) ,  next(nullptr) , prev(nullptr){

    }
};

class DoublyLinklist{
    public:
        Node *head = nullptr;
        Node *tail = nullptr;
        DoublyLinklist(int value){
            Node *NN = new Node(value);
        }
        DoublyLinklist(){
            head = tail = nullptr;
        }
        void insert(int value){ // Time Complexity O(1)
            Node *NN = new Node(value);
            if(head == nullptr){
                head = NN;
                tail = NN;
            }else {
                tail->next = NN;
                NN->prev = tail;
                tail = NN;
            }
        }
        void NodeTobeDeleted(Node* node){ // Time Complexity O(1)
            if(node == head){
                head = node->next;
                if(head) head->prev = nullptr; 
                else tail = nullptr;

            }else if(node == tail){
                tail = node->prev;
                if(tail) tail->next = nullptr;
                else head = nullptr;

            }
            else{
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            delete node;
        }
        void display(){ // Time Complexity : 0(n)
            Node* temp = head;
            while ( temp != nullptr){
                cout<< temp->data<<" -> ";
                temp = temp->next;
            }if(temp == nullptr){
            cout<<"NULL"<<endl;
            }
        }
        
};

int main(){
    DoublyLinklist dl;
    dl.insert(12);
    dl.insert(16);
    dl.insert(18);
    dl.insert(23);
    dl.display();    
    dl.NodeTobeDeleted(dl.head->next->next);
    dl.display();
}