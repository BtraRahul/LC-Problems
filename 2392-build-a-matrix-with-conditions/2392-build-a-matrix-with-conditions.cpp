class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pR) {
        int n = numCourses;

        sort(pR.begin(), pR.end());
        // vector<int> inDegree(n+1, 0), outDegree(n+1, 0);
        set<pair<int, int>> vis;
        unordered_map<int, int> inDegree, outDegree;
        vector<vector<int>> edges(n + 1);
        for (auto row : pR) {
            // row : {a,b} b->a  outDeg(b)++, inDeg(a)++;
            int a = row[0];
            int b = row[1];

            if (vis.find({a, b}) != vis.end())
                continue;
            vis.insert({a, b});

            inDegree[a]++;
            outDegree[b]++;

            edges[b].push_back(a);
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i <= n; i++)
            if (!inDegree[i])
                q.push(i);

        while (q.size()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (int node : edges[curr]) {
                inDegree[node]--;

                // node have no pre Req. if its inDegree is 0;
                if (inDegree[node] == 0) {
                    q.push(node);
                }
            }
            cout<<endl;
        }

        if (ans.size() < n) // cycle found
            return {};
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<int> row = findOrder(k, rowConditions);
        // cout<<endl;
        vector<int> col = findOrder(k, colConditions);


        if (row.empty() || col.empty())
            return {};

        reverse(row.begin(), row.end());
        reverse(col.begin(), col.end());

        // for(int e: row) cout<<e<<endl;
        // for(int e: col) cout<<e<<" ";

        unordered_map<int, pair<int, int>> mp;

        int i = 0, j = 0; // row index

        for (int r : row) {
            if (!r)
                continue;    // if the number is 0, ignore it
            mp[r].first = i; // assign idx
            i++;
        }

        for (int c : col) {
            if (!c)
                continue;
            mp[c].second = j;
            j++;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (auto p : mp) {
            int num = p.first;
            int x = p.second.first;
            int y = p.second.second;

            ans[x][y] = num;
        }

        stack<int> remaining;

        for (int t = 1; t <= k; t++) {
            if (mp.find(t) == mp.end()) {
                remaining.push(t);
            }
        }
        for (i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (!ans[i][j] && remaining.size()) {
                    ans[i][j] = remaining.top();
                    remaining.pop();
                }
            }
        }

        return ans;
    }
};