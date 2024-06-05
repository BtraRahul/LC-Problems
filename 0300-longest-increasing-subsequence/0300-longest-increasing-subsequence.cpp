class Solution {
    vector<int> memo;

public:
    int helper(vector<int>& nums, int i = 0) {
        int n = nums.size();
        int ans = 1;

        if (memo[i] != -1)
            return memo[i];
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i])
                ans = max(ans, 1 + helper(nums, j));
        }

        return memo[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, n = nums.size();
        memo.resize(n, -1);

        for (int i = 0; i < n; i++) {
            ans = max(ans, helper(nums, i));
        }

        return ans;
    }
};