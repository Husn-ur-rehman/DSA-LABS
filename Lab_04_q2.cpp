#include<bits/stdc++.h>
using namespace std;

bool backspace(string t,string s){
    stack<char> st;
    stack<char> ss;

    for( char i : t){

        if( i == '#'){
            st.pop();
        }
        else{
            st.push(i);
        }
    }
    for( char i : s){
        
        if( i == '#'){
            ss.pop();
        }
        else{
            ss.push(i);
        }
        
    }
    if(st.size() == ss.size()){
        return true;
    }
    return false;

}
int main(){
    string one, two;
    cin>> one;
    cin >> two;
    if(backspace(one,two)){
        cout<<"TRUE";

    }else cout<<"FALSE";
}