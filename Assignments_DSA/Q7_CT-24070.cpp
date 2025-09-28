#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Linklist{
    public:
    int size = 0;
    Node* head = nullptr;  // start of the list
    Node* tail = nullptr; // end of the list

        Linklist(): head(nullptr), tail(nullptr) {} // initialize a list

        void insert_at_tail(int val){ // Time Complexity: O(1) , Space Complexity: O(1)
            Node* NN = new Node(val);
            if(head == nullptr){ // base case
                head = NN;
                tail = NN;

            }else if(tail == head){ // if only one node is present
                tail = NN;
                head->next = tail;
            }else { // average case
                tail->next = NN;
                tail = NN;
            }
            size++;
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
        void insert(int val,int pos){ // Time Complexity O(n)
            Node *NN = new Node(val);
            if(pos > size){ 
                cout<<"Invalid";
            return;
            }

            if(pos == 0){ 
                NN->next = head;
                head = NN;
            }else if(pos == size){
                tail->next = NN;
                tail = NN;
            }else{
                Node *curr = head;
                for( int i = 0 ; i < pos - 1 ; i++){
                    curr = curr->next;
                }
                NN->next = curr->next;
                curr->next = NN;
            }
            size++;
        }
    };

    int main(){
        Linklist L1;
        L1.insert_at_tail(1);
        L1.insert_at_tail(3);
        L1.insert_at_tail(4);
        L1.insert_at_tail(5);
        L1.display();
        L1.insert(2,2);
        L1.display();

        return 0;
    }