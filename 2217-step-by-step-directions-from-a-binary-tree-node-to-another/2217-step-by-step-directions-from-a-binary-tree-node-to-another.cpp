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

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void helper(TreeNode* root, unordered_map<int, TreeNode*>& parent) {
//         if (!root)
//             return;

//         if (root->left)
//             parent[root->left->val] = root;
//         if (root->right)
//             parent[root->right->val] = root;

//         helper(root->left, parent);
//         helper(root->right, parent);
//     }

//     TreeNode* LCA(int sv, int dv, auto& parent) {}
//     string getDirections(TreeNode* root, int startValue, int destValue) {

//         unordered_map<int, TreeNode*> parent; // to maintain parent of Nodes;
//         unordered_map<int, int> vis;          // keep track of visited nodes
//         queue<pair<TreeNode*, string>> q;     // bfs
//         // q: {nodeVal, path} path is the path from src to the particular
//         node

//         // determine parent-child pairs
//         helper(root, parent);

//         // we don't really need to traverse entire tree, find lowest common
//         // ancestor (LCA)

//         TreeNode* common = NULL;
//         TreeNode *sv = NULL, *dv = NULL;

//         // q.push({common, ""});
//         cout << common->val;
//         return "";

//         TreeNode* startParent = parent[startValue];
//         if (startParent) {
//             if (startParent->left && startParent->left->val == startValue) {
//                 sv = startParent->left;
//             } else {
//                 q.push({startParent->right, ""});
//             }
//         } else {
//             // root is the startNode;
//             sv = startParent->left;
//         }

//         while (q.size()) {
//             pair<TreeNode*, string> t = q.front();
//             TreeNode* curr = t.first;
//             string path = t.second;
//             q.pop();

//             if (curr->val == destValue)
//                 return path;

//             // push children
//             TreeNode *l = curr->left, *r = curr->right;

//             if (l && !vis[l->val]) {
//                 vis[l->val] = 1;
//                 q.push({l, path + 'L'});
//             }
//             if (r && !vis[r->val]) {
//                 vis[r->val] = 1;
//                 q.push({r, path + 'R'});
//             }
//         }

//         return "-1";
//     }
// };

class Solution {

public:
    bool findPath(TreeNode* root, int value, string& path) {
        if (root->val == value)
            return true;

        if (root->left && findPath(root->left, value, path))
            path += 'L';
        else if (root->right && findPath(root->right, value, path))
            path += 'R';

        return path.size();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {

        string sv, dv;
        findPath(root, startValue, sv);
        findPath(root, destValue, dv);
        // cout << sv << "\n" << dv;

        reverse(sv.begin(), sv.end());
        reverse(dv.begin(), dv.end());

        if (sv.size() == 0)
            return dv;

        string final;
        if (dv.size() == 0) {
            for (char c : sv) {
                final += 'U';
            }
            return final;
        }

        int i = 0, j = 0;
        while (i < sv.size() && j < dv.size()) {
            if (sv[i] != dv[j])
                break;

            i++, j++;
        }

        return string(sv.size()-i, 'U')+string(dv.begin()+j, dv.end());

    }
};