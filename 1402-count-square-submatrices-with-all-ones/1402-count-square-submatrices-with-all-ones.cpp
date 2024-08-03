class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> newMatrix(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    newMatrix[i][j] = matrix[i][j];
                else if (matrix[i][j] == 0) {
                    newMatrix[i][j] = 0;
                } else {
                    newMatrix[i][j] =
                        min({newMatrix[i - 1][j],     // up
                             newMatrix[i - 1][j - 1], // diagonally up
                             newMatrix[i][j - 1]}) +  // left
                        1;
                }
            }
        }
        
        int sum =0;

        for (auto row : newMatrix) {
            for (int e : row) {
                sum+=e;
            }
        }

        return sum;
    }
};