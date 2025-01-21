#define pii pair<int, int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frq;

        for (int ele : nums) {
            frq[ele]++;
        }

        priority_queue<pii, vector<pii>, greater<>> pq;

        for (auto [ele, f] : frq) {
            pq.push({f, ele});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while (pq.size()) {
            auto [frq, ele] = pq.top();
            pq.pop();
            ans.push_back(ele);
        }

        return ans;
    }
};