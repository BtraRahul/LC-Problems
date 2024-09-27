class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> newArr(n);
        int idx = 0 ;

        for(int i = 0;i<n;i++){
            if(nums[i] > 0){
                newArr[idx] = nums[i];
                idx+=2;
            }
        }
        idx = 1;
        for(int i = 0;i<n;i+=1){
            if(nums[i] < 0){
                newArr[idx] = nums[i];
                idx+=2;
            }
        }

        return newArr;
    }
};