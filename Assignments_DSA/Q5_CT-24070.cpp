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
        void display(){
            Node* temp = head;
            while ( temp != nullptr){
                cout<< temp->data<<" -> ";
                temp = temp->next;
            }if(temp == nullptr){
            cout<<"NULL"<<endl;
            }
        }
        Node* mergeTwoLists(Node* list1, Node* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        Node *head =nullptr;

        if(list1->data < list2->data){
            head = list1;
            list1 = list1->next;
        }else{
            head = list2;
            list2 = list2->next;
        }
        Node *tail=head;

        while(list1 && list2){
            if(list1->data < list2->data){
                tail->next =list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;

        }
        if(list1){
            tail->next = list1;
        } 
        else{
            tail->next = list2;
        }
        return head;
    }

};

int main(){
    Linklist L1;
    L1.insert_at_tail(1);
    L1.insert_at_tail(3);
    L1.insert_at_tail(5);
    L1.insert_at_tail(7);
    
    Linklist L2;
    L2.insert_at_tail(2);
    L2.insert_at_tail(4);
    L2.insert_at_tail(6);
    L2.insert_at_tail(8);

    Linklist L3;
    L3.head = L3.mergeTwoLists(L1.head, L2.head);
    cout<<"Merged List is: ";
    L3.display();
    return 0;
}