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
// 1st approach
//  1. traverse the tree, find the leaf nodes
//  2. for every leaf, find pairs
//  3. maintain map: parent[child]=node;
//  4. we might find duplicate pairs, so avoid this by just going to right;

// 2nd approach, find levels and LCA
// 1. consider 2 leaves at a time, find the LCA
// 2. it's a good pair if dist from leaves to LCA <=d
// 3. for this, find level of each node;
//  more complex and higher time complexity
class Solution {

public:
    void setParent(TreeNode* root, map<TreeNode*, TreeNode*>& parent,
                   TreeNode* topNode = NULL) {
        if (!root)
            return;

        parent[root] = topNode;

        setParent(root->left, parent, root);
        setParent(root->right, parent, root);
    }
    int findPairs(TreeNode* root, auto& parent, int maxD) {

        queue<pair<TreeNode*, int>> q;
        unordered_map<TreeNode*, int> vis;
        q.push({root, 0});
        vis[root] = 1;

        int ans = 0;

        while (q.size()) {
            auto f = q.front();
            q.pop();
            TreeNode* curr = f.first;
            int dist = f.second;

            if (!curr)
                continue;
            if (dist && dist <= maxD && !curr->left && !curr->right) {
                ans++;
            }

            if (dist > maxD)
                continue;
            // push the parent
            TreeNode* p = parent[curr];
            if (p) {
                // cout << p->val;
                if (!vis[p]) {
                    vis[p] = 1;
                    q.push({p, dist + 1});
                }
            }

            TreeNode* left = curr->left;
            if (left && !vis[left]) {
                vis[left] = 1;
                q.push({left, dist + 1});
            }

            TreeNode* right = curr->right;
            if (right && !vis[right]) {
                vis[right] = 1;
                q.push({right, dist + 1});
            }

            // cout << q.size() << " ";
        }

        return ans;
    }
    void traverse(TreeNode* root, int& ans, int& distance, auto& parent) {

        if (!root)
            return;

        if (!root->left && !root->right)
            ans += findPairs(root, parent, distance);

        traverse(root->left, ans, distance, parent);
        traverse(root->right, ans, distance, parent);
    }
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*, TreeNode*> parent;
        setParent(root, parent);
        cout << parent.size();
        int ans = 0;
        traverse(root, ans, distance, parent);

        return ans / 2;
    }
};