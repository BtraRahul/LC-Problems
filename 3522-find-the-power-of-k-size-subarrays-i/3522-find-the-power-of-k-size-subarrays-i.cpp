class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 1;

        vector<int> ans(n - k + 1, -1);
        if (n == 1 || k == 1)
            return nums;

        while (j < n) {
            while (j < n && j - i + 1 < k) {
                if (nums[j] - 1 != nums[j - 1])
                    i = j;
                j++;
            }
            if (j == n)
                break;

            if (nums[j] - 1 != nums[j - 1]) {
                i = j, j++;
                continue;
            }
            ans[i] = nums[j];
            i++, j++;
        }

        return ans;
    }
};