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

class CircularLinklist{
    public:
    Node *head;
    Node *tail;
    int count = 0;
    CircularLinklist(): head(nullptr), tail(nullptr){}

    void insert(int value){
        Node *NN = new Node(value);
        if(head == nullptr){
            head = NN;
            tail = NN;
            tail->next = head;

        }else{
            tail->next = NN;
            tail = NN;
            tail->next = head;
        }
        count++;
    }
    void display(){
        Node *temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
            if(temp == head) break;
        }
    }
    void RotateList(int k){
        int n = k % count;
        Node *temp = head;
        for(int i = 1 ; i < count - n; i++){
            temp = temp->next;
        }
        head = temp->next;
        tail = temp;
    }



};
int main(){
    CircularLinklist cl;
    cl.insert(1);
    cl.insert(2);
    cl.insert(3);
    cl.insert(4);
    cl.insert(5);
    cl.display();
    cout<<endl;
    cl.RotateList(2);
    cl.display();
    return 0;
}
