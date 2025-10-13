#include<bits/stdc++.h>
using namespace std;

class Solution {
    int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
    public:
        string InfixToPostfix(string test){
            string ans = "";
            stack<char> st;
            int s = test.size();
            for ( int i = 0; i < s; i++){
                if(isalnum(test[i])){ // for variables;
                    ans += test[i];
                }
                else if( test[i] == '(' ){
                    st.push(test[i]);
                }
                else if( test[i] == ')'){ // for brackets case;
                    while( !st.empty() && st.top() != '(' ){
                        ans += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else {
                    while(!st.empty() && precedence(st.top()) >= precedence(test[i])){ // for operator precedence;
                    ans += st.top();
                    st.pop();
                    }
                    st.push(test[i]);
                }

            }

            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
            return ans;
        }
};
int main(){
    string testing = "(A+B)*C";//not use space;
    Solution obj;
    cout<<obj.InfixToPostfix(testing);

}