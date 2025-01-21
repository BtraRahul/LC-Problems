class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0, end = n - 1;

        if (n == 1)
            return nums[0] == target ? 0 : -1;

        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            int midEle = nums[mid];
            int leftEle = nums[beg];
            int rightEle = nums[end];

            if (midEle == target)
                return mid;
                
            // look for the sorted half
            if (leftEle <= midEle) {
                if (leftEle <= target && target <= midEle) {
                    end = mid - 1;
                } else
                    beg = mid + 1;
            } else if (midEle <= rightEle) {
                if (midEle <= target && target <= rightEle) {
                    beg = mid + 1;
                } else
                    end = mid - 1;
            }
        }

        return -1;
    }
};