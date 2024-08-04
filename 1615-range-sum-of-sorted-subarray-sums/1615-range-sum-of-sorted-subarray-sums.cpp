class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        priority_queue<int> pq;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum = (sum + nums[j]) % mod;

                if (pq.size() < right) {
                    pq.push(sum);
                } else if (pq.size() >= right) {
                    if (pq.top() > sum) {
                        pq.pop();
                        pq.push(sum);
                    } else
                        continue;
                }
            }
        }

        // cout<<pq.top();

        int finalSum = 0;
        int i = 0;
        while (i < right - left + 1) {
            finalSum = (finalSum + pq.top()) % mod;
            pq.pop();
            i++;
        }

        return finalSum;
    }
};