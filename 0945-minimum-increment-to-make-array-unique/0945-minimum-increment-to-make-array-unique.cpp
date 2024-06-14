class Solution {
public:
    //[3,2,1,2,1,7]
    //  1,1,2,2,3,7
    //  1 2 3 4 5 7
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = 0;
        for (int i = 0; i < n - 1; i++) {
            cout << nums[i] << " ";
            if (nums[i + 1] <= nums[i]) {
                ans += (nums[i] - nums[i + 1]) + 1;
                nums[i + 1] = nums[i] + 1;
            }
        }
        cout << nums[n - 1];

        return ans;
    }
};