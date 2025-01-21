class Solution {
public:
    void helper(int n, int k, vector<int>& nums, vector<vector<int>> &ans,vector<int>&temp, unordered_map<int, int> &mp){
        if(k==0) {
            ans.push_back(temp);
            return ;
        }

        for(int i=0;i<n;i++){
            if(mp[i]==1) continue;
            mp[i]=1;
            temp[n-k]=nums[i];
            helper(n, k-1, nums, ans, temp, mp );
            mp[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> temp(n);
        unordered_map<int, int> mp;
        helper(n, n, nums,ans, temp, mp);
        return ans;
    }
};