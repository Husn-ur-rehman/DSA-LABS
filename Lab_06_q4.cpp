#include<bits/stdc++.h>
using namespace std;

vector<int> pancakeSort(vector<int>& arr) {
    vector<int> result;
    int n = arr.size();
    
    for (int curr_size = n; curr_size > 1; curr_size--) {

        int maxIndex = max_element(arr.begin(), arr.begin() + curr_size) - arr.begin();

        if (maxIndex != curr_size - 1) {
            if (maxIndex != 0) {
                reverse(arr.begin(), arr.begin() + maxIndex + 1);
                result.push_back(maxIndex + 1);
            }

            reverse(arr.begin(), arr.begin() + curr_size);
            result.push_back(curr_size);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {3, 2, 4, 1};
    vector<int> res = pancakeSort(arr);

    cout << "Flip sequence: ";
    for (int k : res)
        cout << k << " ";
    cout << "\nSorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
