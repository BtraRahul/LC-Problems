class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 1st approach: iterate the array, and if ith number is repeated
        // thrice, arr[i]=arr[i+1] untill i=n tc: O(n*n) sc:O(1)

        // 2nd approach, change all numbers which are the 3rd repetition to X
        // and shift all at once tc:O(n+n) sc:O(1)

        int count = 1;
        int rem = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == nums[i + count])
                count++;
            else
                count = 1;

            if (count >= 3) {
                rem++;
                nums[i] = INT_MAX;
            }
        }

        int i = 0, j = 0;

        while (i <= j && j < nums.size()) {
            while (j < nums.size() && nums[j] == INT_MAX)
                j++;

            nums[i] = nums[j];
            i++, j++;
        }
        return nums.size() - rem;
    }
};