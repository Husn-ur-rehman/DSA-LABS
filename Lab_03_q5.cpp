#include<bits/stdc++.h>
using namespace std;

class BrowserHistory {
    struct Node{
        string value;
        Node* prev;
        Node* next;
        Node(string val){
            value = val;
            prev = nullptr;
            next = nullptr;
        }
    };
public:
    Node* current;
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url){
        Node* temp = current->next;
        while (temp){
            Node* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
        current->next = new Node(url);
        current->next->prev = current;
        current = current->next;
    }
    string back(int steps){
        for(int i = 0; i < steps && current->prev != nullptr;i++){
            current = current->prev;
        }     
        return current->value;
    }
    
    string forward(int steps) {
        for(int i = 0; i < steps && current->next != nullptr;i++){
            current = current->next;
        }     
        return current->value;
        
    }
};
int main(){
    BrowserHistory* obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");
    cout<<obj->back(1)<<endl;
    cout<<obj->back(1)<<endl;
    cout<<obj->forward(1)<<endl;
    obj->visit("linkedin.com");
    cout<<obj->forward(2)<<endl;
    cout<<obj->back(2)<<endl;
    cout<<obj->back(7)<<endl;
    return 0;
}