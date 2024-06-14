class Solution {
public:
    bool isJudge(int n, int judge, auto& mp) {
        for (int i = 1; i <= n; i++) {
            if (i == judge)
                continue;

            bool found = false;
            for (auto j : mp[i])
                if (j == judge) {
                    found = true;
                    break;
                }
            if (!found)
                return false;
        }

        return true;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int, vector<int>> mp;

        for (auto r : trust)
            mp[r[0]].push_back(r[1]);

        for (auto it : mp) {
            cout << it.first << ": ";
            for (auto j : it.second)
                cout << j << " ";
            cout << endl;
        }

        int ans = -1;
        bool found = false;

        for (int i = 1; i <= n; i++) {
            if (mp.find(i) == mp.end()) {
                if (isJudge(n, i, mp)) {
                    if (!found) {
                        found = true;
                        ans = i;
                    } else
                        return -1;
                }
            }
        }

        return ans;
    }
};