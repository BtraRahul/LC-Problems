class Solution {
    int count = 0;
    vector<int> subtreeSize;

public:
    void dfs(auto& size, auto& tree, int node, int parent) {
        bool isGood = true;
        int expectedSize = -1;

        set<int> st;
        for (auto neighbor : tree[node]) {
            if (neighbor == parent)
                continue;

            dfs(subtreeSize, tree, neighbor, node);
            size[node] += size[neighbor];

            st.insert(size[neighbor]);
        }

        if (st.size() <= 1)
            count++;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> tree(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        subtreeSize.resize(n, 1);
        dfs(subtreeSize, tree, 0, 0);

        return count;
    }
};
