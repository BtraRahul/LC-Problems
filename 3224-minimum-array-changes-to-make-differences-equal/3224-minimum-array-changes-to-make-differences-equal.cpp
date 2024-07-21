class Solution {
public:
    int helper(int d, vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - i - 1];
            // cout << i << " ";
            if (abs(a - b) == d)
                continue;

            if (a > b)
                swap(a, b);

            if ((b - 0 >= d) || (k - a >= d) || (b - a) > d) {
                count++;
            } else
                count += 2;
        }

        return count;
    }
    int minChanges(vector<int>& nums, int k) {
        map<int, int> mp;

        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            int d = abs(nums[i] - nums[n - i - 1]);
            mp[d]++;
        }

        int ans = INT_MAX;

        vector<int> diff;

        int dif = -1;
        int f = 0;
        for (auto p : mp) {

            if (f < p.second) {
                f = p.second;
                dif = p.first;
            }
            diff.push_back(p.first);
        }

        sort(diff.begin(), diff.end());
        // for (int d : diff) {
        //     // if (mp[d] == 0)
        //     //     continue;
        //     int val = helper(d, nums, k);
        //     cout << d << ":" << mp[d] << " = " << val << "\n";
        //     ans = min(ans, val);
        // }

        // calc ans for median diff
        // sort(diff.begin(), diff.end());

        int size = diff.size();
        // if (size % 2) {
            ans = min(ans, helper(diff[size / 2], nums, k));
        // } else {
        //     // ans = min(ans, helper(diff[size / 2], nums, k));
        //     ans = min(ans, helper(diff[size / 2] + 1, nums, k));
        // }

        // ans for most freq difference

        cout << dif;
        ans = min(ans, helper(dif, nums, k));

        return ans;
    }
};