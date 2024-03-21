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
    int final;

public:
    pair<int, int> helper(TreeNode* root) {
        int rt = root->val;
        pair<int, int> ans = {rt, rt};

        int lf = 0, ls = 0, rf = 0, rs = 0;

        if (root->left) {
            pair<int, int> small = helper(root->left);
            lf = small.first;
            ls = small.second;
        }
        if (root->right) {
            pair<int, int> small = helper(root->right);
            rf = small.first;
            rs = small.second;
        }

        if (root->left && root->right) {
            ans.first = max(ans.first, ans.first + max(lf, rf));
            ans.second = max({ans.second, ls, rs, rf + lf + rt});
        } else if (root->right && !root->left) {
            ans.first = max(ans.first, ans.first + rf);
            ans.second = max({ans.second, rs, rf + rt});
        } else if (!root->right && root->left) {
            ans.first = max(ans.first, ans.first + lf);
            ans.second = max({ans.second, ls, lf + rt});
        }

        cout << ans.first << " " << ans.second << endl;
        final = max({final, ans.first, ans.second});
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;

        final = INT_MIN;
        pair<int, int> ans = helper(root);

        return final;
    }
};