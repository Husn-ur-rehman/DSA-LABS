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
        void deleteNode(int count){ // Time Complexity : 0(n)
            while( head!= nullptr && count!=0){
                Node* temp = head;
                head = head->next;
                delete temp;
                --count;
            }
        }
    };
    Node* DeleteNode(Node* head, int count) {
    while (head != nullptr && count != 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        --count;
    }
    return head;
}
int main(){
    Linklist L;
    L.insert_at_tail(1);
    L.insert_at_tail(2);
    L.insert_at_tail(3);
    L.insert_at_tail(4);
    L.insert_at_tail(5);
    L.insert_at_tail(6);
    L.display();
    L.deleteNode(2);
    cout << "After deletion: "; 
    L.display();
    cout << endl;
    return 0;
}