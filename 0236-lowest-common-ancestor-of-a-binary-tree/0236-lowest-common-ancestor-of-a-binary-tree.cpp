/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> par;
    unordered_map<TreeNode*, int> vis;

    void parent(TreeNode* root, TreeNode* curr) {
        if (!curr)
            return;

        par[curr] = root;
        parent(curr, curr->left);
        parent(curr, curr->right);
    }

public:
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root)
            return root;
        par[root] = NULL;
        parent(root, root->left);
        parent(root, root->right);
        // for p;
        while (p) {
            if (vis[p])
                return p;
            vis[p] = 1;

            p = par[p];
        }

        while (q) {
            if (vis[q])
                return q;
            vis[q] = 1;

            q = par[q];
        }

        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p||root==q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right) return root;

        if(left) return left;

        return right;
    }
};