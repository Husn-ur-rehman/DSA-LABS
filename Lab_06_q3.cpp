#include<bits/stdc++.h>
using namespace std;

class Sort{
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
    void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];        // current element to insert
        int j = i - 1;

        // shift elements to the right until correct spot found
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;        // insert key at correct position
    }
}    
    void display(vector<int> test){
        for(int i = 0; i < test.size();i++)
        cout<<test[i]<<" ";
    }
};
int main(){
    Sort obj;
    vector<int> testing = {23,14,214,432,54,21,};
    obj.insertionSort(testing);
    obj.display(testing);
}