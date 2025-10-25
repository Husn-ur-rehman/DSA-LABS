#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool palindrome(const string testing,int start,int end){
        if(start > end ){
            cout<<"TRUE"<<endl;
            return true;
        }

        if( testing[start] != testing[end]){
        cout<<"False"<<endl;
        return false;
        }

        return palindrome(testing,start + 1, end - 1);
    } 
};

int main(){
    Solution obj;
    string test;
    cin>>test;
    obj.palindrome(test,0,test.size()-1);

}