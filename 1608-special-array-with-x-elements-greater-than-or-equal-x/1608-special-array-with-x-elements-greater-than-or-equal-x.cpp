class Solution {
    // [0,4,3,0,4,2,4,1,3,4]
    // [0,0,1,2,3,3,4,4,4,4]

    // [11,11,11,11,11,11,11,11,11,11,11]  n=11
    // 0 11 -> 5(lower bound->idx=0) if(n-idx >= 5) 6,11  (11-0 >=5)
    // 6 11 -> 8(idx) 9,11  (11-0>=8)
    // 9 11 -> 10 idx 11,11 (11-0 >= 10)
    // 11 11->11 idx (11-0>=11)
public:
    // bsearch
    int specialArray(vector<int>& nums) {
        int ans = 0;
        int left = 0, right = nums.size();
        sort(nums.begin(), nums.end());
        for (int i : nums)
            cout << i << " ";
        cout << endl;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            cout << mid << " ";
            int idx = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
            cout << idx << "\n";
            int size = nums.size() - idx;
            // if(mid > size) return -1;
            if ((size) >= mid) {
                if (mid == size)
                    ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }

        return ans == 0 ? -1 : ans;
    }
    // int specialArray(vector<int>& nums) {
    //     priority_queue<int, vector<int>, greater<int>> pq;

    //     for (int i : nums)
    //         pq.push(i);

    //     int ans = 0;

    //     while (pq.size()) {
    //         if (ans > pq.size())
    //             return -1;
    //         ans = max(ans, (int)pq.size());

    //         if (ans <= pq.top() && ans == pq.size())
    //             return ans;
    //         ans = pq.top() + 1;
    //         pq.pop();
    //     }

    //     return -1;
    // }
};