#include<bits/stdc++.h>
using namespace std;

class Stack{
    int top;
    int capacity;
    int* arr;
    public:
    Stack(int cap){
        capacity = cap;
        top = -1;
        arr = new int[cap];
    }
    bool isFull(){
        return top == capacity - 1;
    }
    bool isEmpty(){
        return top == -1;
    }
    void push(int val){
        if(isFull()){
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }
    int peek(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return -1; // Indicating stack is empty
        }
        return arr[top];
    }
    void display(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        for(int i = top ; i >= 0 ; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // Output: 30 20 10
    cout << "Top element is: " << s.peek() << endl; // Output: 30
    s.pop();
    s.display(); // Output: 20 10
    return 0;
}