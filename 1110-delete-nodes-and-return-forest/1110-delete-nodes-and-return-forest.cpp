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
public:
    void helper(TreeNode* parent, TreeNode* child, unordered_set<int>& st,
                vector<TreeNode*>& ans) {
        if (!child)
            return;

        // if the child has to be deleted
        int val = child->val;

        helper(child, child->right, st, ans);
        helper(child, child->left, st, ans);

        if (st.find(val) != st.end()) {
            if (parent) {
                if (parent->right && parent->right->val == val)
                    parent->right = NULL;
                if (parent->left && parent->left->val == val)
                    parent->left = NULL;

                if (child->left)
                    ans.push_back(child->left);

                if (child->right)
                    ans.push_back(child->right);
            }
        }
    }

    void delNodesHelper(TreeNode* root, unordered_set<int>& st,
                        vector<TreeNode*>& ans) {

        if (!root)
            return;

        if (st.find(root->val) != st.end()) {
            delNodesHelper(root->left, st, ans);
            delNodesHelper(root->right, st, ans);
        } else {
            ans.push_back(root);
            helper(NULL, root, st, ans);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        vector<TreeNode*> ans;

        delNodesHelper(root, st, ans);

        return ans;
    }
};