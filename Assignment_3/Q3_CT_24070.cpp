#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int fib(int nth){
        if( nth == 0 ) return 0;
        if(nth == 1) return 1;

        return fib(nth - 1) + fib(nth - 2);
    }

};

int main(){
    Solution obj;
    int test;
    cin>>test;
    for(int i = 0; i < test;i++){
        cout<<obj.fib(i)<<" ";
    }

}