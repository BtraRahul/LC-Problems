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
    vector<vector<int>> v;

public:
    void helper(TreeNode* root, int level) {
        if (!root)
            return;

        if (v.size() == level)
            v.resize(v.size() + 1);
        v[level].push_back(root->val);

        helper(root->left, level + 1);
        helper(root->right, level + 1);
    }
    bool isEvenOddTree(TreeNode* root) {

        int level = 0;
        helper(root, level);

        for (auto row : v) {
            for (int ele : row)
                cout << ele << " ";
            cout << "\n";
        }

        for (int i = 0; i < v.size(); i += 2) {
            if (i >= v.size())
                break;
            if (v[i][0] % 2 == 0)
                return false;
            for (int j = 0; j < v[i].size() - 1; j++) {
                if (v[i][j] >= v[i][j + 1] || (v[i][j] % 2) == 0 ||
                    (v[i][j + 1] % 2) == 0)
                    return false;
            }
            if (i + 1 >= v.size())
                break;
            if (v[i + 1][0] % 2 != 0)
                return false;
            for (int j = 0; j < v[i + 1].size() - 1; j++) {
                if (v[i + 1][j] <= v[i + 1][j + 1] || v[i + 1][j] % 2 ||
                    v[i + 1][j + 1] % 2)
                    return false;
            }
        }

        return true;
    }
};