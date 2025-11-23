#include<bits/stdc++.h>

using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};

class BinarySearchTree {
    public:
    TreeNode* root;
    BinarySearchTree() : root(NULL) {}
    void insert(int key) {
        root = insertRec(root, key);
        }
    void deleteNode(int key) {
        root = deleteRec(root, key);
    }
    void inorder() {
        inorderRec(root);
        cout<<endl;
    }
        // Recursive function to insert a node
        TreeNode* insertRec(TreeNode* node, int key) {
        // Base case: if the tree is empty, create a new node
        if (node == NULL)
            return new TreeNode(key);
        // Otherwise, recur down the tree
        if (key < node->val)
            node->left = insertRec(node->left, key);
        else if (key > node->val)
            node->right = insertRec(node->right, key);
        return node;
    }
    // Recursive function to delete a node
    TreeNode* deleteRec(TreeNode* node, int key) {
        // Base case: if the tree is empty
        if (node == NULL)
            return node;
        // Recur down the tree
        if (key < node->val)
            node->left = deleteRec(node->left, key);
        else if (key > node->val)
            node->right = deleteRec(node->right, key);
        else {
            // Node with only one child or no child
            if (node->left == NULL) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } 
        else if (node->right == NULL) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = minValueNode(node->right);
        // Copy the inorder successor's content to this node
        node->val = temp->val;

        // Delete the inorder successor
        node->right = deleteRec(node->right, temp->val);
        }
        return node;
    }
    // Find the node with the minimum value (used for deleting nodes)
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL)
        current = current->left;
        return current;
    }
    // Inorder traversal function
    void inorderRec(TreeNode* root) {
        if (root != NULL) {
        inorderRec(root->left);
        cout << root->val << " ";
        inorderRec(root->right);
        }
    
    }

    void PreOrderTraversal(TreeNode* testing){
        //base case;        
        if(testing == nullptr) return;

        cout<< testing->val<< " ";
        //left case;
        PreOrderTraversal(testing->left);
        //right case:
        PreOrderTraversal(testing->right);

    }

    void PostOrderTraversal(TreeNode* testing){
        //base case;
        if(testing == nullptr) return;

        PostOrderTraversal(testing->left);
        PostOrderTraversal(testing->right);

        cout<<testing->val<<" ";
    }

    void postorderIterative(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* cur = st1.top();
            st1.pop();

            st2.push(cur);  // push root after children

            if (cur->left) st1.push(cur->left);
            if (cur->right) st1.push(cur->right);
        }

        while (!st2.empty()) {
            cout << st2.top()->val << " ";  
            st2.pop();
        }
    }
    void preorderIterative(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();

            cout << cur->val << " ";       // Visit root

            if (cur->right) st.push(cur->right);   // right goes first
            if (cur->left) st.push(cur->left);     // left goes on top
        }
    }


};



int main(){

    BinarySearchTree test;
    test.insert(4);
    test.insert(7);
    test.insert(3);
    test.insert(1);
    test.insert(2);

    test.PostOrderTraversal(test.root);
    cout<<endl;
    test.PreOrderTraversal(test.root);
    cout<<endl;
    test.postorderIterative(test.root);
    cout<<endl;
    test.preorderIterative(test.root);

}

