#include<bits/stdc++.h>
using namespace std;

class Sort{
    public:
    int Sorting_Techniques(vector<int> &test){
        char input;
        cout<<"\nWHICH SORTING TECHNIQUE YOU WOULD LIKE TO CHOSE "<<endl<<"A. BUBBLE SORT"<<endl<<"B. INSERTION SORT"<<endl<<"C. SELECTION SORT"<<endl;
        cin>>input;
        switch(input){
            case 'A':{
                return BubbleSort(test);
                break;
            }
            case 'B':{
                return insertionSort(test);
                break;
            }
            case 'C':{
                return SelectionSort(test);
                break;
            }
        }
        return 0;
    }
    int BubbleSort(vector<int> &test){
        int comparasions = 0;
        int swaps = 0;
        
        for( int i = 0; i < test.size() ; i++ ){
            for( int j = i; j < test.size(); j++){
                comparasions++;
                if(test[i] > test[j]){
                    swap(test[i],test[j]);
                    swaps++;
                }
            }
        }
        cout<<"No. of swaps done are :"<<swaps<<endl;
        cout<<"No. of comparisions done are :"<<comparasions<<endl;
        return comparasions + swaps;
    }
    int insertionSort(vector<int>& arr) {
        int compares = 0;
        int swaps = 0;
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key && compares++) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }

            arr[j + 1] = key;
        }
        cout<<"No. of swaps done are :"<<swaps<<endl;
        cout<<"No. of comparisions done are :"<<compares<<endl;
        return compares + swaps;
    }
    int SelectionSort(vector<int> &test){
        int comparasions = 0;
        int swaps = 0;
        int n = test.size();

        for(int i = 0; i < n-1; i++){
            int min__ind = i;
            for(int j = i + 1; j < n; j++){
                comparasions++;
                if(test[j] < test[min__ind]) min__ind = j;
            }
            if(min__ind != i){
                swap(test[i],test[min__ind]);
                swaps++;
            }
        }
        cout<<"No. of swaps done are :"<<swaps<<endl;
        cout<<"No. of comparisions done are :"<<comparasions<<endl;
        return comparasions + swaps;

    }   

    void display(vector<int> test){
        for(int i = 0; i < test.size();i++)
        cout<<test[i]<<" ";
    }

};
int main(){

    Sort obj;
    int n = 0;

    cout<<"INPUT THE SIZE OF THE ARRAY YOO"<<endl;
    cin>>n;

    vector<int> testing(n);
    srand(time(0));

    for (int i = 0; i < n; i++)
        testing[i] = rand() % 100;
    
    vector<int> I = testing, B = testing, S = testing;
    cout << "Original Arrays: "<<endl;
    obj.display(testing);

    cout<<"\nBubble Sort :"<<endl;
    int tot_ops_B = obj.BubbleSort(B);
    
    cout<<"\nInsertion Sort :"<<endl;
    int tot_ops_I = obj.insertionSort(I);
    
    cout<<"\nSelection Sort :"<<endl;
    int tot_ops_S = obj.SelectionSort(S);

    vector<pair<string,int>> results = {
        {"Bubble Sort",tot_ops_B},
        {"Insertion Sort", tot_ops_I},
        {"Selection Sort", tot_ops_S}
    };
    
    sort(results.begin(), results.end(),
        [](auto& a, auto& b) { return a.second < b.second; });

    cout << "\nBest Technique: " << results[0].first << " (Least operations: " << results[0].second << ")" << endl;
    cout << "Worst Technique: " << results.back().first << " (Most operations: " << results.back().second << ")" << endl;
    
    obj.Sorting_Techniques(testing);
    obj.display(testing);

    

}