class Solution {
    int maxEle = 0;

public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int& e : arr) {
            e = ((e % k) + k) % k;
            mp[e]++;
        }

        sort(arr.begin(), arr.end());
        
        if(mp[0]&1) return false;
        for (int i = 1; i <= k / 2; i++) {
            if (mp[i] != mp[k - i])
                return false;
        }
        
        return true;
    }
};