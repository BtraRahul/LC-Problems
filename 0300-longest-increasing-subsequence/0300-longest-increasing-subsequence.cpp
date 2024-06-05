class Solution {
    vector<int> memo;

public:
    // int helper(auto& nums, int i, int prev) {
    //     if (i >= nums.size())
    //         return 1;

    //     int ans = 1, n = nums.size();
    //     if (memo[i] + 1)
    //         return memo[i];

    //     for (int j = i; j < n; j++) {
    //         if (nums[j] > prev)
    //             ans = max(ans, 1 + helper(nums, j + 1, nums[j]));
    //     }

    //     return memo[i] = ans;
    // }
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int ans = 1, n = nums.size();
        // memo.resize(n, -1);

        // for (int i = 0; i < n; i++) {
        //     ans = max(ans, helper(nums, i + 1, nums[i]));
        // }

        // return ans;

        vector<int> dp(n, 1);        

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans=max(dp[i], ans);
                }
            }
        }
        return ans;
    }
};