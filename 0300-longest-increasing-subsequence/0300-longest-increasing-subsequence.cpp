class Solution {
    vector<int> memo;

public:
    int helper(vector<int>& nums, int i = 0) {
        int n = nums.size();

        if (memo[i] != -1)
            return memo[i];
        memo[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i])
                memo[i] = max(memo[i], 1 + helper(nums, j));
        }

        return memo[i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, n = nums.size();
        memo.resize(n, -1);

        for (int i = 0; i < n; i++) {
            ans = max(ans, helper(nums, i));
        }

        return ans;
    }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, 1);
    //     int ans = 1;

    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             if (nums[j] > nums[i]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //                 ans = max(ans, dp[i]);
    //             }
    //         }
    //     }

    //     return ans;
    // }
};