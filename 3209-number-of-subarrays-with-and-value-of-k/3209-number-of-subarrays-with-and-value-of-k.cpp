class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;
        for (long long i = 0; i < 1e10; i++) {
            int a=1;
        }
        unordered_map<long long, long long> prev;

        for (int i = 0; i < n; ++i) {
            unordered_map<long long, long long> curr;
            curr[nums[i]] = 1;

            // if already k, atleast 1 ans possible
            if (nums[i] == k) {
                count++;
            }

            // check agar AND karne se answer aata hai ki nahi, then update the
            // map values with updated one
            for (auto p : prev) {
                long long v = p.first, f = p.second, calc = v & nums[i];
                if (calc == k) {
                    count += f;
                }
                curr[calc] += f;
            }

            prev = curr;
        }

        return count;
    }
};
