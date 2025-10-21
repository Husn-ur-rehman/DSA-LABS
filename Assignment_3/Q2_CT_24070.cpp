#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int sum_digits(int nums){
        if(nums == 0) return 0;

        return nums%10 + sum_digits(nums/10);
    }
};

int main(){
    Solution obj;
    int test;
    cin>>test;
    cout<<obj.sum_digits(test);

}