#include<bits/stdc++.h>
using namespace std;

class DataStream {
    public:
    int val;
    int k;
    vector<int> stream;

    DataStream(int value, int k) {
        this->val = value;
        this->k = k;
    }
    bool consec( int value){
        stream.push_back(value);
        if( stream.size() < k ) return false;
        for(int i = stream.size() - k; i < stream.size(); i++){
            if( stream[i] != val ) return false;
        }
        return true;
    }
};
int main(){
    DataStream* obj = new DataStream(4, 3);
    cout<<obj->consec(4)<<endl;
    cout<<obj->consec(4)<<endl;
    cout<<obj->consec(4)<<endl;
    cout<<obj->consec(3)<<endl;
    cout<<obj->consec(4)<<endl;
    return 0;
}