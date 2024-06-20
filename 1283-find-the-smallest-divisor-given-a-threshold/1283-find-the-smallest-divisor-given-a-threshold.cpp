class Solution {
public:
    bool possible(vector<int>& dist, int threshold, int num) {
        int res = 0;

        for (int i = 0; i < dist.size(); i++) {
            int d = dist[i];

            res += ceil(d / (num * 1.0));

            if (res > threshold)
                return false;
        }

        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int beg = 1, end = 1e5;
        // return 0;
        int ans = -1;

        while (beg <= end) {
            int mid = (beg + end) / 2;

            if (possible(nums, threshold, mid)) {
                ans = mid;
                end = mid - 1;
            } else
                beg = mid + 1;
        }

        return ans;
    }
};