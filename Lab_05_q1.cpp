#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque{
    int *arr;
    int size;
    int front;
    int rear;
    int capacity;
    public:
    MyCircularDeque(int k) : capacity(k), size(0), front(-1), rear(-1) {
        arr = new int[k];
        
    }
    bool insertFront (int val){
        if(size == capacity) return false;
        if ( size == 0 ) front = rear = 0;
        else front = (front - 1 + capacity) % capacity;
        arr[front] = val;
        size++;
        return true;
    }
    bool insertLast (int val){
        if(size == capacity) return false;
        if ( size ==  0 ) front = rear = 0;
        else rear = (rear + 1)% capacity;
        arr[rear] = val;
        size++;
        return true;
    }
    bool deleteFront (){
        if( size  == 0 ) return false;
        if ( size == 1 ) front =  rear  = -1;
        if( size > 1) front = (front + 1 )% capacity;
        size--;
        return true; 
    }
    bool deleteLast (){
        if( size  == 0  ) return false;
        if( size == 1 )front = rear = -1;
        if( size > 1 ) rear = (rear -1 + capacity)% capacity;
        size--;
        return true;
    }
    int getFront (){
        if( size == 0 ) return -1;
        return arr[front];
    }
    int getRear () {
        if(size ==  0 ) return -1;
        return arr[rear];
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity ;

    }
    void display(){
        if(size == 0){
            cout<<"Deque is empty"<<endl;
            return;
        }
        for(int i = 0; i < size; i++){
            cout<<arr[(front + i) % capacity]<<" ";
        }
        cout<<endl;
    }
    ~MyCircularDeque(){
        delete[] arr;
    }
};

int main() {
    MyCircularDeque myCircularDeque(3); 
    myCircularDeque.insertLast(1); 
    myCircularDeque.insertLast(2);    
    myCircularDeque.insertFront(3);   
    myCircularDeque.insertFront(4); // return false, the queue is full
    myCircularDeque.display();    // display called 
    myCircularDeque.getRear();        
    myCircularDeque.isFull();         
    myCircularDeque.deleteLast();
    myCircularDeque.display();     // display called
    myCircularDeque.insertFront(4);
    myCircularDeque.display();     // display called
    myCircularDeque.getFront();       
}