// class Solution {
// "4"  3  0
// "4"  2  0
// "3" "2" "1"

// [1,1,1,1,0,0,0]
// [0,0,0,1,0,0,0]
// [0,0,0,1,0,0,1]
// [1,0,0,1,0,0,0]
// [0,0,0,1,0,0,0]
// [0,0,0,1,0,0,0]
// [0,0,0,1,1,1,1]
// public:
// bool isValid(auto& grid, int i, int j) {
//     int n = grid.size();

//     return i >= 0 && i < n && j >= 0 && j < n && grid[i][j] >= 0;
// }
// int cherryPickup(vector<vector<int>>& grid) {
//     int n = grid.size();

//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     dp[n - 1][n - 1] = grid[n - 1][n - 1];
//     for (int i = n - 1; i >= 0; i--) {
//         for (int j = n - 1; j >= 0; j--) {
//             if (i == n - 1 && j == n - 1)
//                 continue;
//             if (grid[i][j] >= 0) {
//                 int a = (isValid(grid, i + 1, j)) ? dp[i + 1][j] : -1;
//                 int b = (isValid(grid, i, j + 1)) ? dp[i][j + 1] : -1;

//                 if (a == -1 && b == -1)
//                     return 0;

//                 dp[i][j] = grid[i][j] + max(a, b);
//             }
//         }
//     }

// for (auto row : dp) {
//     for (int e : row)
//         cout << e << " ";
//     cout << endl;
// }

// mark all cherries picked

// int ans = dp[0][0];

// int i = 0, j = 0;

// while (j < n && i < n) {
//     grid[i][j] = 0;

//     int a = (isValid(grid, i + 1, j)) ? dp[i + 1][j] : 0;
//     int b = (isValid(grid, i, j + 1)) ? dp[i][j + 1] : 0;

//     if (a >= b) {
//                 i++;
//             } else {
//                 j++;
//             }
//         }

//         // do it again
//         dp[n - 1][n - 1] = grid[n - 1][n - 1];
//         for (i = n - 1; i >= 0; i--) {
//             for (j = n - 1; j >= 0; j--) {
//                 if (i == n - 1 && j == n - 1)
//                     continue;
//                 if (grid[i][j] >= 0) {

//                     int a = (isValid(grid, i + 1, j)) ? dp[i + 1][j] :
//                     -1; int b = (isValid(grid, i, j + 1)) ? dp[i][j + 1]
//                     : -1;

//                     if (a == -1 && b == -1)
//                         return 0;

//                     dp[i][j] = grid[i][j] + max(a, b);
//                 }
//             }
//         }

//         for (auto row : dp) {
//             for (int e : row)
//                 cout << e << " ";
//             cout << endl;
//         }

//         return dp[0][0] + ans;

//         // return ans;
//     }
// };
class Solution {

    bool isValid(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        return i >= 0 && i < n && j >= 0 && j < n && grid[i][j] >= 0;
    }

    int dxdy[2][2] = {{1, 0}, {0, 1}};

public:
    // int helper(vector<vector<int>>& grid, int i, int j, int p, int q,
    //            vector<vector<vector<int>>>& dp) {
    //     int n = grid.size();
    //     if (!isValid(grid, i, j) || !isValid(grid, p, q))
    //         return INT_MIN;

    //     if (i == n - 1 && j == n - 1)
    //         return grid[i][j];

    //     if (dp[i][j][p] != INT_MIN)
    //         return dp[i][j][p];

    //     int current = (i == p) ? grid[i][j] : grid[i][j] + grid[p][q];

    //     int best = max({
    //         helper(grid, i + 1, j, p + 1, q, dp),
    //         helper(grid, i + 1, j, p, q + 1, dp),
    //         helper(grid, i, j + 1, p + 1, q, dp),
    //         helper(grid, i, j + 1, p, q + 1, dp),
    //     });

    //     return dp[i][j][p] = current + best;
    // }

    // int cherryPickup(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     vector<vector<vector<int>>> dp(
    //         n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
    //     int result = helper(grid, 0, 0, 0, 0, dp);
    //     return max(0, result);
    // }

    // tabulation
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));

        dp[n - 1][n - 1][n - 1] = grid[n - 1][n - 1];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int p = n - 1; p >= 0; p--) {
                    int q = i + j - p;
                    if (q < 0 || q >= n || grid[i][j] < 0 || grid[p][q] < 0)
                        continue;

                    int curr = (i == p) ? grid[i][j] : grid[i][j] + grid[p][q];
                    for (int k = 0; k < 2; k++) {
                        for (int l = 0; l < 2; l++) {
                            int new_i = i + dxdy[k][0];
                            int new_j = j + dxdy[k][1];
                            int new_p = p + dxdy[l][0];
                            int new_q = q + dxdy[l][1];

                            if (isValid(grid, new_i, new_j) &&
                                isValid(grid, new_p, new_q)) {
                                dp[i][j][p] =
                                    max({dp[i][j][p],
                                         curr + dp[new_i][new_j][new_p]});
                            }
                        }
                    }
                }
            }
        }

        return max(0, dp[0][0][0]);
    }
};