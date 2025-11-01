#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int BubbleSort(vector<int> &test,int &k){
        for( int i = 0; i < test.size() ; i++ ){
            for( int j = i; j < test.size(); j++){
                if(test[i] > test[j]){
                    swap(test[i],test[j]);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < test.size(); i++){
            if(k <= test[i]) return count;
            if(k > test[i]){ 
            k -= test[i];
            count++;
            }
        }
        return count;
    }
};

int main(){
    vector<int> testing = {1,12,5,111,200,1000,10};
    int money;
    cin>>money;
    Solution obj;
    cout<<"No of toys that can be bought are :"<<obj.BubbleSort(testing,money)<<endl;
    cout<<"REMAINING AMOUNT : "<<money;
}