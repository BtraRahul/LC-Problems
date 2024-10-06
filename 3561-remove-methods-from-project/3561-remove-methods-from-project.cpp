class Solution {
    unordered_map<int, int> inf, notr;

public:
    void findInf(int n, auto& graph, int k) {

        queue<int> q;
        vector<int> vis(n, 0);
        q.push(k);

        while (q.size()) {
            int f = q.front();
            q.pop();
            if (vis[f])
                continue;
            vis[f] = 1;
            inf[f] = 1;

            for (auto e : graph[f]) {
                q.push(e);
            }
        }
    }
    void nonR(int n, auto& graph) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inf[i] == 0)
                q.push(i);
        }

        vector<int> vis(n, 0);

        while (q.size()) {
            int f = q.front();
            q.pop();
            if (vis[f])
                continue;
            vis[f] = 1;
            notr[f] = 1;

            for (int e : graph[f]) {
                q.push(e);
            }
        }
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);
        for (auto& i : invocations) {
            int s = i[0];
            int d = i[1];

            graph[s].push_back(d);
        }

        findInf(n, graph, k);
        nonR(n, graph);
        vector<int> all(n);
        for (int i = 0; i < n; i++)
            all[i] = i;
        vector<int> ans;

        for (auto p : notr) {
            ans.push_back(p.first);
            if (inf[p.first] == notr[p.first])
                return all;
        }
        return ans;
    }
};