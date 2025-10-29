#include<bits/stdc++.h>
using namespace std;

class Sort{
    public:
    void Sorting_Techniques(vector<int> &test){
        char input;
        cout<<" WHICH SORTING TECHNIQUE YOU WOULD LIKE TO CHOSE "<<endl<<"A . BUBBLE SORT"<<endl<<"B. INSERTION SORT"<<endl<<"C.SELECTION SORT"<<endl;
        cin>>input;
        switch(input){
            case 'A':{
                BubbleSort(test);
                break;
            }
            case 'B':{
                insertionSort(test);
                break;
            }
            case 'C':{
                SelectionSort(test);
                break;
            }
        }
    }
    void BubbleSort(vector<int> &test){
        
        for( int i = 0; i < test.size() ; i++ ){
            for( int j = i; j < test.size(); j++){
                if(test[i] > test[j]) swap(test[i],test[j]);
            }
        }
    }
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }
    void SelectionSort(vector<int> &test){
        int n = test.size();
        for(int i = 0; i < n-1; i++){
            int min__ind = i;
            for(int j = i; j < n; j++){
                if(test[j] < test[min__ind]) min__ind = j;
            }
            swap(test[i],test[min__ind]);
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
    obj.Sorting_Techniques(testing);
    obj.display(testing);

}