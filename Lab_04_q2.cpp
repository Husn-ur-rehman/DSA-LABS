#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspace(string s, string t) {
    stack<char> st;
    stack<char> ss;

    for( char i : t){

        if( i == '#'){
            if(st.empty()) continue;
            st.pop();
        }
        else{
            st.push(i);
        }
    }
    for( char i : s){
        
        if( i == '#'){
            if(ss.empty()) continue;
            ss.pop();
        }
        else{
            ss.push(i);
        }
        
    }
    while(!st.empty()&&!ss.empty()){
        if(st.top() == ss.top()){
            st.pop();
            ss.pop();
        } 
        else return false;
    }
    if(st.empty() && ss.empty()) return true;
    return false;
        
        
    }
};
int main(){
    string one, two;
    cin>> one;
    cin >> two;
    Solution obj;
    if(obj.backspace(one,two)){
        cout<<"TRUE";

    }else cout<<"FALSE";
}