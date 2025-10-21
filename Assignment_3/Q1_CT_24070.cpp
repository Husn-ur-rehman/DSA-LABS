#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int fact(int k){
        if(k == 0) return 1;
        if(k == 1) return 1;
        
        return k * fact(k - 1);
    }
};

int main(){
    int factorialnum;
    cin>>factorialnum;
    Solution obj;
    cout<<endl<<obj.fact(factorialnum);
}