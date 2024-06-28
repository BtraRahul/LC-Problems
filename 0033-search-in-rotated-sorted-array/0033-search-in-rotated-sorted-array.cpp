class Solution {

    // 1,2,3,4,5,6,7,8,9
    // 7,8,9,1,'2',3,4,5,6   t=1;
    // 7,'8',9,1
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0, end = n - 1;

        while (beg <= end) {
            int mid = beg + (end - beg) / 2;

            if (nums[mid] == target)
                return mid;

            if(nums[beg]<=nums[mid]){
                if(target >= nums[beg] && target<nums[mid]) end=mid-1;
                else beg=mid+1;
            }else{
                if(target > nums[mid] && target<=nums[end]) beg=mid+1;
                else end=mid-1;
            }         
        }

        return -1;
    }
};