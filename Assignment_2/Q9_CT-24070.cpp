#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enqueue(int x) {

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue() {
        if (s1.empty()) {
            cout << "Queue is empty"<<endl;
            return -1;
        }
        int val = s1.top();
        s1.pop();
        return val;
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 
    q.enqueue(40);
    cout << q.dequeue() << endl; 
}
