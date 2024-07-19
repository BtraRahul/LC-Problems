class Solution {
public:
    int helper(string s, int st, int e, int k) {
        if (st < 0 || e >= s.size() || st > e || e - st + 1 < k)
            return 0;

        unordered_map<char, int> mp;

        for (int i = st; i <= e; i++) {
            mp[s[i]]++;
        }

        int ans = 0;
        int found = 0;

        for (int i = st; i <= e; i++) {
            if (mp[s[i]] < k) {
                found = 1;
                ans = max(ans, helper(s, st, i - 1, k));
                while (i <= e && mp[s[i]] < k) {
                    i++;
                }
                ans = max(ans, helper(s, i, e, k));
            }
        }

        if (found == 0)
            return e - st + 1;
        return ans;
    }
    int longestSubstring(string s, int k) {
        if (k == 0)
            return s.size();
        if (k > s.size())
            return 0;

        return helper(s, 0, s.size() - 1, k);
    }
};