class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size(), maxAns = 1, maxCount = 0;
        vector<int> dp(n, 1), count(n, 0);
        count[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxAns = max(maxAns, dp[i]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((dp[j] == dp[i] - 1) && nums[i] > nums[j]) {
                    count[i] += count[j];
                }
            }
            if (dp[i] == 1)
                count[i] = 1;
            if (dp[i] == maxAns)
                maxCount += count[i];
        }

        return maxCount;
    }
};