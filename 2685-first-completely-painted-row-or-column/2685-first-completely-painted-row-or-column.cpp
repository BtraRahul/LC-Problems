class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>>
            mp; // maps elements to their corresponding row,col
        unordered_map<int, int> row,
            col; // tracks how many elements are unmarked for each row and col

        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ele = mat[i][j];
                mp[ele] = make_pair(i, j);

                row[i]++;
                col[j]++;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            int r = mp[arr[i]].first;
            int c = mp[arr[i]].second;

            row[r]--;
            col[c]--;

            if (!row[r] || !col[c])
                return i;
        }

        return arr.size() - 1;
    }
};