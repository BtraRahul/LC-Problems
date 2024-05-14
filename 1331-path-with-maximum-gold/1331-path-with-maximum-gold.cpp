class Solution {
    vector<vector<int>> vis;

public:
    bool isvalid(auto& grid, int i, int j) {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size();
    }

    int dxdy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int helper(auto& grid, int sx, int sy) {

        int ans = 0;

        vis[sx][sy] = 1;
        for (int k = 0; k < 4; k++) {
            int newx = sx + dxdy[k][0];
            int newy = sy + dxdy[k][1];
            if (isvalid(grid, newx, newy) && grid[newx][newy] &&
                !vis[newx][newy]) {
                ans = max(ans, helper(grid, newx, newy));
            }
        }
        vis[sx][sy] = 0;

        return grid[sx][sy] + ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        vis.resize(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    int v = helper(grid, i, j);
                    ans = max(ans, v);
                }
            }
        }

        return ans;
    }
};