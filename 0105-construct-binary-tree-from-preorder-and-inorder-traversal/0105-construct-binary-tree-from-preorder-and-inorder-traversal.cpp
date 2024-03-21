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
    int it;

public:
    TreeNode* helper(auto& pr, auto& in, int l, int r) {
        if (r < l)
            return NULL;

        int rt;
        for (int i = 0; i < in.size(); i++) {
            if (pr[i] == INT_MAX)
                continue;

            rt = pr[i];
            pr[i] = INT_MAX;
            break;
        }
        TreeNode* root = new TreeNode(rt);

        for (int j = l; j <= r; j++) {
            if (rt == in[j]) {
                root->left = helper(pr, in, l, j - 1);
                root->right = helper(pr, in, j + 1, r);
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return NULL;

        int rt = preorder[0];
        TreeNode* root = new TreeNode(rt);

        int it, l, r;

        preorder[0] = INT_MAX;
        l = 0, r = inorder.size() - 1;

        for (int j = 0; j <= r; j++) {
            if (rt == inorder[j]) {
                root->left = helper(preorder, inorder, l, j - 1);
                root->right = helper(preorder, inorder, j + 1, r);
            }
        }

        return root;
    }
};