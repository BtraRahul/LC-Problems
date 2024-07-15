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
    // n=descriptions.size(), M=number of nodes
    // time complexity: O(n+M) n
    // space complexity: o(M)
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes, parents;

        for (auto row : descriptions) {
            int parent = row[0];
            int child = row[1];
            bool isLeft = row[2];

            // if parent doesn't exist, create one
            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }

            // same for the child
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }

            TreeNode* p = nodes[parent];
            TreeNode* c = nodes[child];

            // assign child to parent
            parents[child] = p;
            if (isLeft)
                p->left = c;
            else
                p->right = c;
        }

        for (auto entry : nodes) {
            int node = entry.first;

            if (parents.find(node) == parents.end())
                return nodes[node];
        }

        return NULL;
    }
};