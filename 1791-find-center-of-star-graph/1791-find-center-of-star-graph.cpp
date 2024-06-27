class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;

        mp[edges[0][0]]++;
        mp[edges[0][1]]++;
        mp[edges[1][0]]++;
        mp[edges[1][1]]++;

        for (auto r : mp)
            if (r.second >= 2)
                return r.first;

        return -1;
    }
};