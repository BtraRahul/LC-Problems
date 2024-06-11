class Solution {
    unordered_map<int, int> idx;

public:
    static bool comp(int& a, int& b, unordered_map<int, int>& idx) {
        return idx[a] < idx[b];
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        for (int i = 0; i < arr2.size(); i++) {
            idx[arr2[i]] = i;
        }
        int n = arr2.size();
        for (int e : arr1)
            if (idx.find(e) == idx.end())
                idx[e] = n + e;

        sort(arr1.begin(), arr1.end(),
             [this](int& a, int& b) { return comp(a, b, idx); });

        return arr1;
    }
};