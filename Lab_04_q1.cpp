#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s){
    stack<char> st;
    for(char i : s){
        st.push(i);

    }
    string reverse = "";
    while(!st.empty()){
        reverse += st.top();
        st.pop();
    }
    if(reverse == s){
        return true;
    }else{
        return false;
    }
}
   

int main(){
    string s;
    cin>> s;
    if(ispalindrome(s)){
        cout<< " True";
    }else{
        cout<< " False";
    }
}