#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> TwoD_array = {
        {2,4,8,5,},
        {5,3,23,6},
        {8,65,3,23,4,}
    };
    vector<int> arr;

    for(int i = 0;i < TwoD_array.size();i++){
        for(int j = 0 ; j < TwoD_array.size(); j++){
            arr.push_back(TwoD_array[j][i]);
        }
    }
    cout<<"The converted array is by col major order"<<endl;
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }

}