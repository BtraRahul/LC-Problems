class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int ans = -1, max_freq = 0;
        unordered_map<int, int> f;

        for (auto r : edges) {
            f[r[0]]++, f[r[1]]++;
            if (f[r[0]]>max_freq) max_freq=f[r[0]], ans=r[0];
            if (f[r[1]]>max_freq) max_freq=f[r[1]], ans=r[1];
        }

        return ans;
    }
};