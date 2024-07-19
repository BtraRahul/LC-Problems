class Solution {
public:
    bool check(auto& matrix, int i, int j) {
        int num = matrix[i][j];

        for (int r = 0; r < matrix.size(); r++) {
            if (matrix[r][j] > num)
                return false;
        }

        return true;
    }
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < matrix.size(); i++) {
            int r = 0, col = 0;
            int m = INT_MAX;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (m > matrix[i][j]) {
                    m = matrix[i][j];
                    r = i;
                    col = j;
                }
            }

            if (check(matrix, r, col))
                ans.push_back(matrix[r][col]);
        }
        return ans;
    }
};