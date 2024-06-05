class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int max_kadane = kadanes(nums);  // Max subarray sum using standard Kadane's algorithm
        int total_sum = 0;
        
        for (int i = 0; i < n; i++) {
            total_sum += nums[i];
            nums[i] = -nums[i];  // Invert the signs
        }
        
        int max_circular = total_sum + kadanes(nums);  // Total sum minus the minimum subarray sum

        // If all numbers are negative, max_circular would be zero, in that case return max_kadane
        if (max_circular == 0) {
            return max_kadane;
        }
        
        return max(max_kadane, max_circular);
    }

private:
    int kadanes(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        
        for (int num : nums) {
            sum += num;
            ans = max(ans, sum);
            if (sum < 0)
                sum = 0;
        }
        
        return ans;
    }
};
