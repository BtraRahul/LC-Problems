class Solution {

    // [23,2,4,6,7]
    //  0 23 25 29 35 42
    //    23 2  6  12  19

    // 23,2,6,4,7
    // 0 23 25 31 35 42

public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();

        vector<int> pre(n);
        // pre[0]=0;
        pre[0] = nums[0];

        unordered_map<int, int> mp; // sum: idx
        for (int i = 1; i < n; i++) {
            pre[i] = nums[i] + pre[i - 1];
            mp[pre[i]] = i;

            if (!(pre[i] % k))
                return true;

            if (nums[i] == 0 && nums[i - 1] == 0)
                return true;
        }

        int mult = pre.back() / k;

        mp[pre[0]] = 0;

        // for (int i : pre)
            // cout << i << " ";

        for (int i : pre) {

            for (int m = 1; m <= mult; m++) {
                int sum = i + m * k;
                // cout << endl << sum;

                if (mp.find(sum) != mp.end() && mp[i] != mp[sum]) {
                    if (mp[sum] - mp[i] >= 2)
                        return true;

                    int n1 = nums[mp[i]];
                    int n2 = nums[mp[sum]];

                    if (!(n1 % k) && !(n2 % k))
                        return true;
                    return false;
                }
            }
        }

        return false;
    }
};