class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount=0;
        int n=nums.size();
        vector<int> ans(n);
        int product=1;
        for(auto x: nums){
            if(x==0) zeroCount++;
            product*=x;
        }
        if(zeroCount>=2){
            ans.resize(n,0);
            return ans;
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) {
                int mul=1;
                for(int j=0;j<n;j++){
                    if(i!=j) mul*=nums[j];
                }
                ans[i]=mul;
            }
            else{
                ans[i]=product/nums[i];
            }
        }
        return ans;
    }
};