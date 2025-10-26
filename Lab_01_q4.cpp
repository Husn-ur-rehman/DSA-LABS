#include<bits/stdc++.h>
using namespace std;

int Binary_Search(const vector<int> &arr,int tar){
    int low = 0;
    int high = arr.size()-1;
    while(low <= high){

        int mid = ( low + high )/2;         
        if(arr[mid] == tar){
            return mid;
        }

        if(arr[mid] < tar){
            low = mid +1 ;    
        }

        if(arr[mid] > tar){
            high = mid -1;    
        }
        
    }
    return -1;

}
int main(){
    vector<int> arr = {-1,0,3,5,9,12};
    cout<<Binary_Search(arr,9)<<endl;
    cout<<Binary_Search(arr,2);
    return 0;
}