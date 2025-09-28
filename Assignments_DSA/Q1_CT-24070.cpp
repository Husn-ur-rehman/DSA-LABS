#include<bits/stdc++.h>
using namespace std;

vector<int> TargetSum(vector<int>& arr, int target){
    int size = arr.size();
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size; j++){
            if(arr[i]+ arr[j] == target){
                return {i,j};
            }
        }
    }
    return {};
}
int main(){
    vector<int> arr = {3,4,15,324,1412,434,241,4};
    vector<int> res = TargetSum(arr,245);
    
    if(!res.empty()){
        cout<<"Indices are  :"<<res[0]<<","<<res[1]<<endl;
    }
    return 0;
}

