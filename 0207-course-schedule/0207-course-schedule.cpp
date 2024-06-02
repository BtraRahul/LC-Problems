class Solution {
    bool isPossible(auto& pre, int start, int prev) {
        int n = pre.size();

        map<pair<int, int>, int> vis;

        queue<pair<int, int>> q;
        q.push({start, prev});

        while (q.size()) {
            int curr = q.front().first;
            int pr=q.front().second;
            q.pop();

            vis[{curr, pr}] = 1;

            for (int p : pre[curr]) {
                if (p == curr)
                    return false;
                if (vis.find({p, prev}) != vis.end())
                    return false;

                // vis[p] = 1;
                q.push({p, curr});
            }
        }

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pre(numCourses);

        for (auto row : prerequisites) {
            pre[row[0]].push_back(row[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            cout << i << ": ";
            for (int p : pre[i])
                cout << p << " ";
            cout << endl;
        }
        bool ans = true;
        for (int i = 0; i < numCourses; i++) {
            if (!isPossible(pre, i, -1)) {
                cout << i;
                return false;
            }
        }
        return ans;
    }
};