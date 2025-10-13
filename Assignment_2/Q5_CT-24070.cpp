#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalpostfix(vector<string>& tokens) {
        
        stack<int> st;
        for(int i = 0;i < tokens.size(); i++){    
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int b = st.top(); 
                st.pop();
                int a = st.top();
                st.pop();

                if(tokens[i] == "+"){
                    st.push(a+b);
                }
                if(tokens[i] == "-"){
                    st.push(a-b);
                }
                if(tokens[i] == "*"){
                    st.push(a*b);
                }
                if(tokens[i] == "/"){
                    st.push(a/b);
                }
            } else{
                    st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
int main(){

    vector<string> tokens = {"5", "6", "2", "+","*","12","4","/","-"}; 
    Solution obj;
    cout << obj.evalpostfix(tokens);

}