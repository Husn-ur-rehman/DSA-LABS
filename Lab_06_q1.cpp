#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool BubbleSort(vector<int> &test){
        bool flag = false;
        for( int i = 0; i < test.size() ; i++ ){
            for( int j = i; j < test.size(); j++){
                if(test[i] > test[j]){
                    swap(test[i],test[j]);
                    flag =true;
                }
            }
        }
        return flag;
    }
};

int main(){
    vector<int> testing = {8,7,2,6,5};
    Solution obj;
    cout<<obj.BubbleSort(testing)<<endl;
    for(int k = 0; k < testing.size(); k++){
        cout<< testing[k];
    }
}