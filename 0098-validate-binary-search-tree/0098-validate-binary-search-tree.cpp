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
    bool helper(TreeNode* root, long minimum = LLONG_MIN, long maximum = LLONG_MAX) {
        if(!root) return true;

        int val = root->val;
        if(!(val > minimum && val < maximum)) return false;

        return helper(root->left, minimum, val) && helper(root->right, val, maximum);
    }

public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        return helper(root);
    }
};