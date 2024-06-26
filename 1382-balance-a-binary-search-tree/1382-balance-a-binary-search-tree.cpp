/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    vector<int> values;

public:
    void helper(TreeNode* root) {
        if (!root)
            return;

        values.push_back(root->val);

        helper(root->left);
        helper(root->right);
    }
    TreeNode* balance(int s, int e) {
        int mid = (s + e) / 2;
        if (mid < 0 || mid >= values.size() || s > e)
            return NULL;

        TreeNode* newNode = new TreeNode(values[mid]);

        newNode->left = balance(s, mid - 1);
        newNode->right = balance(mid + 1, e);

        return newNode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        helper(root);

        sort(values.begin(), values.end());
        int n = values.size();
        int mid = n / 2;

        root->val = values[mid];
        root->left = balance(0, mid - 1);
        root->right = balance(mid + 1, n - 1);

        return root;
    }
};