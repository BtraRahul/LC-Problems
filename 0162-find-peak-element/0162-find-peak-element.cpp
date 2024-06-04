class Solution {
public:
    bool valid(auto& nums, int i) {

        int n = nums.size();
        if (n == 1)
            return true;
        if (i == 0)
            return nums[0] > nums[1];
        if (i == n - 1)
            return nums[n - 1] > nums[n - 2];

        return nums[i] > nums[i + 1] && nums[i] > nums[i - 1];
    }
    int helper(vector<int>& nums, int i, int j) {
        if (i > j)
            return 0;
        if (i == j)
            return i;

        int mid = (i + j) / 2;
        cout << i << " " << j << ": " << mid << endl;

        if (valid(nums, mid))
            return mid;
        int idx = helper(nums, i, mid - 1);
        if (valid(nums, idx))
            return idx;

        return helper(nums, mid + 1, j);
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // // return nums[n];

        // if (n == 1)
        //     return 0;
        // if (nums[0] > nums[1])
        //     return 0;
        // if (nums[n - 1] > nums[n - 2])
        //     return n - 1;

        // for (int i = 1; i < n - 1; i++) {
        //     cout << i << " ";
        //     if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        //         return i;
        // }

        // return -1;

        // binary search approach
        return helper(nums, 0, n - 1);
    }
};