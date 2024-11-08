class Solution {

    vector<int> bits;

public:
    Solution() { bits.resize(32, 0); }
    void setBitCount(int num) {
        int idx = 0;

        while (num) {
            if (num & 1) {
                bits[idx]++;
            }
            num = num >> 1;
            idx++;
        }
    }
    int largestCombination(vector<int>& candidates) {
        for (int& e : candidates) {
            setBitCount(e);
        }

        return *max_element(bits.begin(), bits.end());
    }
};