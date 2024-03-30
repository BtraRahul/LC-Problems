class Solution {
public:
    int atmost(int k, vector<int>& nums) {
        
        int i = 0, j = 0, ans = 0, n = nums.size();
        unordered_map<int, int> mp;

        while (j < n) {
            mp[nums[j]]++;

            while (i <= j && mp.size() > k) {
                if (--mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            ans += (j - i + 1);

            j++;
        }
        cout << endl;
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        // int j = 0, n = nums.size(), ans = 0;
        // unordered_map<int, int> mp;

        // for (int i = 0; i < n; i++) {
        //     if (i > 0) {
        //         mp[nums[i - 1]]--;
        //         if (mp[nums[i - 1]] == 0)
        //             mp.erase(nums[i - 1]);
        //     }
        //     while (j>0 && j > i + k - 1) {
        //         mp[nums[j]]--;
        //         if (mp[nums[j]] <= 0)
        //             mp.erase(nums[j]);

        //         j--;
        //     }
        //     while (j < n && mp.size() < k) {
        //         mp[nums[j]]++;
        //         if (mp.size() == k)
        //             break;
        //         j++;
        //     }

        //     // mp[nums[j]]++;
        //     while (j<n && mp.size() == k) {
        //         // cout << i << " " << j << " " << mp[nums[i]] << " "
        //         //      << mp[nums[j]] << endl;
        //         j++;
        //         mp[nums[j]]++;
        //         ans++;
        //     }
        // }

        int exact_k = atmost(k, nums) - atmost(k - 1, nums);
        return exact_k;
    }
};