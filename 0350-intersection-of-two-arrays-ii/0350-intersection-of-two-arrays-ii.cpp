class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> f;

        for(int e: nums1) f[e]++;

        for(int e: nums2){
            if(f[e]){
                ans.push_back(e);
                f[e]--;
            }
        }

        return ans;
    }
};