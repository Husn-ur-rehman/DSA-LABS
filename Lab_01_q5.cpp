#include<bits/stdc++.h>
using namespace std;

bool Binary_Search(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();

    int low = 0, high = m * n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / n;
        int col = mid % n;
        int midVal = mat[row][col];

        if (midVal == target) {
            return true;
        } else if (midVal < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    if (Binary_Search(matrix, target)) {
        cout<<"TRUE"<<endl;
    } else{
        cout<<"FALSE"<<endl;
    }

    return 0;
}
