#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void reverse(string &s,int start,int end){
        if(start >= end) return;
        
        swap(s[start],s[end]);
        reverse(s,start + 1, end -1);
    }
};

int main(){
    Solution obj;
    string test;
    cin>>test;
    obj.reverse(test,0,test.size()-1);
    cout<<test;
}
