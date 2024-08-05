#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    vector<vector<pll>> makeGraph(int n, vector<vector<int>>& r) {
        vector<vector<pll>> graph(n);

        for (auto row : r) {
            graph[row[0]].push_back({row[1], row[2]});
            graph[row[1]].push_back({row[0], row[2]});
        }

        return graph;
    }
    vector<ll> helper(auto& graph, int n) {
        ll mod = 1e9 + 7;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        vector<ll> dist(n, LLONG_MAX), ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});

        while (pq.size()) {
            auto t = pq.top();
            pq.pop();
            ll dis = t.first;
            ll node = t.second;

            for (auto adj : graph[node]) {
                ll adjNode = adj.first;
                ll edW = adj.second;

                // reaching a node for the first time with this shorter dist
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                // reaching again with this dist
                else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph = makeGraph(n, roads);
        vector<ll> ways = helper(graph, n);
        int mod = 1e9 + 7;
        return ways[n - 1] % mod;
    }
};