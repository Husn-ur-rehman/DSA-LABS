#include<bits/stdc++.h>
using namespace std;
    
struct TreeNode { 
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
};

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode* convertListToBST(ListNode*& head, int n) {
    if (n <= 0) return NULL;

    TreeNode* leftTree = convertListToBST(head, n / 2);

    TreeNode* root = new TreeNode(head->val);
    root->left = leftTree;

    head = head->next;

    root->right = convertListToBST(head, n - n / 2 - 1);

    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int size = 0;
    ListNode* temp = head;

    while (temp) {
        size++;
        temp = temp->next;
    }

    return convertListToBST(head, size);
}

int main() {
    
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    //sorted linked list to BST
    TreeNode* root = sortedListToBST(head);

    // Inorder traversal of BST
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    };

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}