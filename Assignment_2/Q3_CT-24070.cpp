#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void BinaryConvertion(int t){
            stack<int> st;
            while ( t > 1){
                st.push( t%2 );
                t = t/2;

            }
            st.push(1);
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
        }
        string Bi_Conv(int t){
            stack<int> st;
            string ans;
            while (t > 1){
                st.push(t%2);
                t = t/2;
            }
            st.push(1);
            while (!st.empty()){
                ans += to_string(st.top());
                st.pop();
            }
            return ans;
        }

};
int main(){

    int t = 0;
    cin>>t;
    Solution obj;
    obj.BinaryConvertion(t);
    cout<<endl;
    cout<<obj.Bi_Conv(t);


    return 0;
}