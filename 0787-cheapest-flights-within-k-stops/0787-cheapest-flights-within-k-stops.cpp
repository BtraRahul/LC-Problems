class Solution {
public:
    vector<vector<pair<int, int>>> makeGraph(int n,
                                             vector<vector<int>>& flights) {

        vector<vector<pair<int, int>>> adj(n);
        for (auto path : flights) {
            int start = path[0];
            int next = path[1];
            int dist = path[2];

            adj[start].push_back({next, dist});
        }
        return adj;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj = makeGraph(n, flights);

        vector<int> dis(n, 1e9);
        queue<pair<int, pair<int, int>>> pq;

        dis[src] = 0;
        pq.push({src, {0, 0}});

        while (!pq.empty()) {

            int node = pq.front().first;
            int step = pq.front().second.first;
            int dist = pq.front().second.second;
            pq.pop();

            for (auto& it : adj[node]) {
                int newnode = it.first;
                int newd = it.second;
                if ((newd + dist < dis[newnode]) && step <= k) {
                    dis[newnode] = newd + dist;
                    pq.push({newnode, {step + 1, newd + dist}});
                }
            }
        }

        if (dis[dst] == 1e9) {
            return -1;
        }

        return dis[dst];
    }
};