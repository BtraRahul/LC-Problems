#define pii pair<int, int>
class Solution {
public:
    int maxDistance(vector<vector<int>>& v) {
        int max1 = -1e4, idx1 = -1, max2 = -1e4, idx2 = -1;

        int n = v.size(), ans = -1e4;
        if (n == 1)
            return 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({v[0].back(), 0});
        pq.push({v[1].back(), 1});
        
        for (int i = 2; i < n; i++) {

            if (v[i].back() < pq.top().first)
                continue;
            pq.pop();
            pq.push({v[i].back(), i});
            // if (pq.size() > 2)
            //     pq.pop();
        }

        max2 = pq.top().first, idx2 = pq.top().second;
        pq.pop();
        max1 = pq.top().first, idx1 = pq.top().second;
        pq.pop();

        for (int i = 0; i < n; i++) {
            int low = v[i].front();
            if (i != idx1)
                ans = max(ans, abs(low - max1));
            else
                ans = max(ans, abs(low - max2));
        }

        return ans;
    }
};