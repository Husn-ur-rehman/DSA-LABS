#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    // Simple inorder traversal function
    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
};

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9}; // example input
    Solution sol;

    // BST
    Solution::TreeNode* root = sol.sortedArrayToBST(nums);

    // BST inorder
    cout << "Inorder traversal of BST: ";
    sol.inorderTraversal(root);
    cout << endl;

    return 0;
}
