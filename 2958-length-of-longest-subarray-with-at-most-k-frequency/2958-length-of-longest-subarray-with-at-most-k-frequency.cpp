class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), max_len = 0;
        unordered_map<int, int> mp;

        while (j < n) {
            mp[nums[j]]++;
            if (mp[nums[j]] > k) {
                max_len = max(max_len, j - i);

                while (mp[nums[j]] > k) {
                    mp[nums[i]]--;
                    i++;
                }
            }

            max_len = max(max_len, j - i + 1);
            j++;
        }

        return max_len;
    }
};