class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = 0, currSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);

            if (currSum < 0)
                currSum = 0;
        }

        if (maxSum == 0)
            return *max_element(nums.begin(), nums.end());
        return maxSum;
    }
};