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

int sumOfNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(65);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->right = new Node(22);

    int totalSum = sumOfNodes(root);
    cout << "Sum of all nodes: " << totalSum << endl;

    return 0;
}