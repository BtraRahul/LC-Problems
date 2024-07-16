class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1, a2;

        if (nums.size() <= 2)
            return nums;

        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            if (a1.back() > a2.back())
                a1.push_back(nums[i]);
            else
                a2.push_back(nums[i]);
        }

        int i = 0;

        for (int e : a1)
            nums[i++] = e;
        for (int e : a2)
            nums[i++] = e;

        return nums;
    }
};