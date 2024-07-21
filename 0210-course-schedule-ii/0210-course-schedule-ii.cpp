class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pR) {
        int n = numCourses;
        vector<int> inDegree(n, 0), outDegree(n, 0);

        vector<vector<int>> edges(n + 1);
        for (auto row : pR) {
            // row : {a,b} b->a  outDeg(b)++, inDeg(a)++;
            int a = row[0];
            int b = row[1];

            inDegree[a]++;
            outDegree[b]++;

            edges[b].push_back(a);
        }

        queue<int> q;
        vector<int> ans;
        vector<int> vis(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cout << i << " " << inDegree[i] << endl;
            if (!inDegree[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }

        while (q.size()) {
            int curr = q.front();
            q.pop();

            ans.push_back(curr);

            for (int node : edges[curr]) {

                inDegree[node]--;

                // they have no pre Req. if there inDegree is 0;
                if (inDegree[node] == 0) {
                    q.push(node);
                }
            }
        }

        if (ans.size() < n)
            return {};
        return ans;
    }
};