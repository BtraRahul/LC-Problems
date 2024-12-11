class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
//         map<int, int> mp;
//         if(nums.size()==1) return 1;
//         int maxfrq=2;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
//         for(auto n: nums){
//             if(mp[n-k]==mp[n+k]) continue;
//             if(mp[n-k]>mp[n+k]) {
//                 mp[n]--;
//                 mp[n-k]++;
//                 n=n-k;                
//             }
//             else {
//                 mp[n]--;
//                 mp[n+k]++;
//                 n=n+k;
//             }
            //         }
//         for(auto x: mp){
//             maxfrq=max(maxfrq, x.second);
//         }
//         return maxfrq;
        
        int j=0;
        int n=nums.size();
        int ans=0;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            while(j<n && nums[j]-nums[i]<=2*k)
                j++;
            ans=max(ans, j-i);
        }
        return ans;
         
    }
};