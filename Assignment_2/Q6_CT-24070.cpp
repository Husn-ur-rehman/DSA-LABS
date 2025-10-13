#include<bits/stdc++.h>
using namespace std;


class Stack {
    struct Node {
        int val;
        int minimum;
    };
    vector<Node> st;  // using vector to build the stack manually

public:
    void push(int x) {
        int currMin = st.empty() ? x : min(x, st.back().minimum);
        st.push_back({x, currMin});
    }

    void pop() {
        if (!st.empty()) st.pop_back();
    }

    int top() {
        return st.back().val;
    }

    int get_min() {
        return st.back().minimum;
    }

    bool empty() {
        return st.empty();
    }
};
int main(){
    Stack obj;
    obj.push(2);
    obj.push(5);
    obj.push(1);
    obj.push(29);
    cout<<obj.get_min() << endl;
    obj.pop();
    obj.pop();
    cout<<obj.get_min();

}