#include<bits/stdc++.h>
using namespace std;

void get_permutation(vector<int> &arr, int left, int right) {
    if (left == right) {
        for(int i = 0 ; i <= right ; i++){
            cout<<arr[i] << " ";
        }
        cout<< endl;
    } else {
        for (int i = left; i <= right; i++) {
            swap(arr[left], arr[i]);                 // fix one character
            get_permutation(arr, left + 1, right); // recurse on the rest
            swap(arr[left], arr[i]);                 // backtrack
        }
    }
}

int main() {
    vector<int> array = {1,2,3,};
    get_permutation(array, 0, array.size() - 1);
    return 0;
}
