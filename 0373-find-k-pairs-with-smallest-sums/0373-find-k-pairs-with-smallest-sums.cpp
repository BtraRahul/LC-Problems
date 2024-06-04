class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int e : nums1)
            pq.push({e + nums2[0], 0});

        while (k-- && pq.size()) {
            int idx2 = pq.top().second;
            int sum = pq.top().first;
            pq.pop();

            ans.push_back({sum - nums2[idx2], nums2[idx2]});

            if (idx2 + 1 < m) {
                // sum=some ele of nums1 + nums2[idx2]
                // new sum=(sum - nums2[idx2]) + nums2[idx2+1]
                pq.push({sum - nums2[idx2] + nums2[idx2 + 1], idx2 + 1});
            }
        }

        return ans;
    }
};