class Solution {
public:
    bool helper(vector<vector<int>>& graph, int start) {
        vector<set<int>> nodeSet(2);

        // int set=0; //1st set is zero, next set is 1

        queue<pair<int, int>> q; // set, node;
        nodeSet[0].insert(start);    // belongs to set 0;
        q.push({0, start});
        unordered_map<int, int> vis;
        vis[start] = 1;

        while (q.size()) {
            int currSet = q.front().first;
            int currNode = q.front().second;
            q.pop();
            cout << currSet << " " << currNode << endl;

            int nextSet = !currSet;

            // push all nodes connected to currNode to the next set. if
            // currSet=0; next_set=1

            for (int node : graph[currNode]) {
                // if the node connected to currNode is in the same set as
                // currNode, graph is not bipartite return false;
                if (nodeSet[currSet].find(node) != nodeSet[currSet].end())
                    return false;

                if (vis[node])
                    continue;

                vis[node] = 1;

                nodeSet[nextSet].insert(node);
                q.push({nextSet, node});
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        bool ans = true;
        for (int i = 0; i < n; i++) {
            ans = ans & helper(graph, i);
            if (!ans)
                return false;
        }

        return true;
    }
};