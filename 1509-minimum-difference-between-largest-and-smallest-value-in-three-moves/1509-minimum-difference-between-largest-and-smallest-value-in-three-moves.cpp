class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4)
            return 0;

        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[1], c = nums[2], d = nums[3], w = nums[n - 4],
            x = nums[n - 3], y = nums[n - 2], z = nums[n - 1];

        // no moves done
        // int ans_0 = z - a;

        // 1 move done (remove 1 from right or 1 from left)
        // int ans_1=min(z-b, y-a);

        // 2 moves done one from each, 2 from either of the side

        // 3 move
        int ans = min({
            w - a, // all from right
            x - b, // 2 from right
            y - c, // 1 from right
            z - d  // none from right
        });

        return ans;
    }
};