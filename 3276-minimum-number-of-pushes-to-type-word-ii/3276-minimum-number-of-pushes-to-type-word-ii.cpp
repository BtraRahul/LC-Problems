class Solution {
public:
    int minimumPushes(string word) {

        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        int ans = 0, p=1;

        for (char c : word)
            mp[c]++;

        for (auto detail : mp) {
            char num = detail.first;
            int frq = detail.second;

            pq.push({frq, num});
        }
        
        while (pq.size()) {
            char num = pq.top().second;
            int frq = pq.top().first;
            pq.pop();

            ans += (ceil(p / 8.0)) * frq;
            p++;
        }

        return ans;
    }
};