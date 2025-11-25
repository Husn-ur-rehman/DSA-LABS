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

Node* LCA(Node* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->data > n1 && root->data > n2) {
        return LCA(root->left, n1, n2);
    }
    if (root->data < n1 && root->data < n2) {
        return LCA(root->right, n1, n2);
    }
    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    int n1 = 5, n2 = 15;
    Node* lca = LCA(root, n1, n2);
    if (lca != nullptr) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}