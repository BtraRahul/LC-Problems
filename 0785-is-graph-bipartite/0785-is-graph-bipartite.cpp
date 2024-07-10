class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        map<int, set<int>> st;

        // first set -> 0
        // second set -> 1

        st[0].insert(0);
        queue<pair<int, int>> q; //<node, set>

        int n=graph.size();
        map<int, int> vis;

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                q.push({i, 0});
            vis[i]=1;
            while (q.size()) {
                pair<int, int> f = q.front();
                int currNode = f.first;
                int nextSet = !f.second;

                q.pop();

                for (int node : graph[currNode]) {
                    // if node is in the same set as currNode, return false;
                    // else push
                    int currSet = f.second;
                    if (st[currSet].find(node) != st[currSet].end())
                        return false;

                    if (vis[node])
                        continue;
                    vis[node] = 1;

                    q.push({node, nextSet});
                    st[nextSet].insert(node);
                }
            }
        }

        return true;
    }
};