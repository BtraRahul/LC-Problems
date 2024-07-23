class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vec(begin(mp),
                                   end(mp)); // convert map to vector pair

        auto lambda = [](auto& a, auto& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        };

        sort(begin(vec), end(vec), lambda);

        vector<int> res;
        for (auto& ele : vec) {
            for (int j = 0; j < ele.second; j++) {
                res.push_back(ele.first);
            }
        }
        return res;
    }
};