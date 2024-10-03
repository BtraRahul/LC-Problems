class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        int maxAns = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxAns = max(maxAns, dp[i]);
                }
            }
        }
        vector<int> count(n, 0);
        count[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((dp[j] == dp[i] - 1) && nums[i] > nums[j]) {
                    count[i] += count[j];
                }
            }
            if (dp[i] == 1)
                count[i] = 1;
        }
        cout << maxAns << endl;

        for (int e : dp)
            cout << e << " ";
        cout << endl;
        for (int e : count)
            cout << e << " ";

        int maxCount = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == maxAns)
                maxCount += count[i];
        }

        return maxCount;
    }
};