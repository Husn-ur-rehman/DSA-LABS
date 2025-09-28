#include<bits/stdc++.h>
using namespace std;

bool is_Seen(vector<int> &arr){
    unordered_set<int> seeen;
    for(int num : arr){
        if(seeen.count(num)) return true;
        seeen.insert(num);
    }
    return false;
    
}
int main(){
    vector<int> array = {123,24,32423,14,124,34,21,312};
    if(is_Seen(array)){
        cout<<"True";

    }
    else{
        cout<< "false";
    }
}