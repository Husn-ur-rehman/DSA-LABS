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
    Node* head = nullptr;  // start of the list
    Node* tail = nullptr; // end of the list
    public:
        Linklist(): head(nullptr), tail(nullptr) {} // initialize a list
        void insert_at_tail(int val){
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
        Node* find_middle(){ /// Time Complexity: O(n) , Space Complexity: O(2) == O(1)
            if(head ==  nullptr){
                cout<< "List is empty"<<endl;
                return nullptr;
            }else{
                Node *slow = head;
                Node *fast = head;
                while (fast != nullptr && fast->next != nullptr){ // traverse till fast or its next go out of bounds
                    slow = slow->next;
                    fast = fast->next->next;
                }
                return slow;
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
    Node* mid = L.find_middle();
    if(mid != nullptr){
        cout<<"Middle element is: "<<mid->data<<endl;
    }
    return 0;
}