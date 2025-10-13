#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string reverse(string test){
        stack<char> st;
        string ans;

        for ( int i = 0; i < test.size(); i++ ){
            st.push(test[i]);

        }
        for ( int j = 0; j < test.size(); j++){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
int main(){

    Solution obj;
    string testing;
    cin>>testing;
    cout<<obj.reverse(testing);

    return 0;
}