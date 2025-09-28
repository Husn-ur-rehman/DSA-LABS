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
        Node* reverse() { // Time Complexity: O(n), Space Complexity: O(1)
            if (head == nullptr) {
            cout << "List is empty" << endl;
            return nullptr;
            }

            Node* curr = head;
            Node* temp = nullptr;

            // Traverse and swap next/prev of each node
            while (curr != nullptr) {
                temp = curr->prev;
                curr->prev = curr->next;
                curr->next = temp;
            curr = curr->prev;  // move to the "next" node (which is prev now)
            }

        // Fix head (since temp is last non-null node)
            if (temp != nullptr) {
                head = temp->prev;
        }

            return head;
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
    dl.insert(15);
    dl.insert(19);
    dl.insert(23);
    dl.insert(29);
    dl.display();
    dl.reverse();
    dl.display();

    return 0;
}