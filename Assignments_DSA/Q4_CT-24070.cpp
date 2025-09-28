#include<bits/stdc++.h>
using namespace std;

class Node { //fundamental unit of a linked list
public:
    int data;
    Node* next;
    Node ( int val): data(val), next (nullptr) {
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
        Node* reverse(){ // Time Complexity: O(n) , Space Complexity: O(1)
            if(head == nullptr){
                cout<<"List is empty"<<endl;
                return nullptr;
            }
            Node* prev = nullptr;
            Node* curr = head;
            Node* next;

            while (curr != nullptr) {
                next = curr->next; // Store the next node
                curr->next = prev; // Reverse the current node's pointer
                prev = curr;       // Move pointers one position ahead
                curr = next;
            }
            head = prev; // Update head to the new front of the list
            return head;
        }
        void display(){ // Time Complexity: O(n)
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
    Linklist L;
    L.insert_at_tail(1);
    L.insert_at_tail(2);
    L.insert_at_tail(3);
    L.insert_at_tail(4);
    L.insert_at_tail(5);
    L.insert_at_tail(6);
    L.display();
    L.head = L.reverse();

    L.display();
    return 0;
}
