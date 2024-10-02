class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(!n) return {};
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }

        sort(v.begin(), v.end());
        // for (auto p : v) {
        //     cout << p.first << " " << p.second << endl;
        // }
        int r = 1;
        vector<int> rank(n);
        rank[v[0].second] = 1;

        for (int i = 1; i < n; i++) {
            int idx = v[i].second;
            r++;
            if (v[i].first == v[i - 1].first)
                r--;

            rank[idx] = r;
        }
        return rank;
    }
};