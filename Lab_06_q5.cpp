#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void BubbleSort(vector<int> &test){
        int n = test.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(test[j]<test[i]){
                    swap(test[j],test[i]);
                }
            }
        }
    }

    void display(vector<int> &test){
        int n = test.size();
        for(int i = 0; i < n;i++){
            cout<<test[i];
        }
    }
};



int main(){

    Solution obj;
    vector<int> testing = {1,0,2,1,0,1,0,2,0,1,2,0,2,1,2,};

    obj.BubbleSort(testing);

    obj.display(testing);

}