#include<bits/stdc++.h>
using namespace std;

class Median_finder{
    private:
    vector<int> arr;
    public:

    Median_finder(){

    };
    void addNum(int a){

        arr.push_back(a);
    }
    double findMedian(){
        if((arr.size())%2 == 0){

            return (arr[(arr.size()/2)-1] + arr[arr.size()/2])/2.0;

        }
        else{
            return arr[(arr.size()/2)];
        }
    }
};

int main(){

    Median_finder arr1,arr2;
    arr1.addNum(2);
    arr1.addNum(3);
    arr1.addNum(4);
    cout<<arr1.findMedian()<<endl;

    arr2.addNum(2);
    arr2.addNum(3);
    cout<<arr2.findMedian()<<endl;
    return 0;
}