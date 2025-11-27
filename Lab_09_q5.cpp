#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

void inorderTraversal(Node* root, vector<int>& values) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, values);
    values.push_back(root->data);
    inorderTraversal(root->right, values);
}

int minDiffInBST(Node* root) {
    vector<int> values;
    inorderTraversal(root, values);
    
    int minDiff = INT_MAX;
    for (size_t i = 1; i < values.size(); ++i) {
        minDiff = min(minDiff, values[i] - values[i - 1]);
    }
    return minDiff;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(9);
    root->right = new Node(10);
    root->left->left = new Node(15);
    root->left->right = new Node(18);

    int minDiff = minDiffInBST(root);
    cout << "Minimum difference between values of any two different nodes: " << minDiff << endl;

    return 0;
}