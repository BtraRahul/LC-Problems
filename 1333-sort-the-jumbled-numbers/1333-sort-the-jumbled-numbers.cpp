class Solution {
public:
    int reduce(string str, vector<int>& mapping) {
        for (char& c : str) {
            int n = c - '0';
            c = (mapping[n] + '0');
        }

        return stoi(str);
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++) {
            int n = reduce(to_string(nums[i]), mapping);
            v.push_back({n, i});
        }

        sort(v.begin(), v.end());

        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            cout << v[i].first << " ";
            int idx = v[i].second;
            ans[i] = nums[idx];
        }

        return ans;
    }
};