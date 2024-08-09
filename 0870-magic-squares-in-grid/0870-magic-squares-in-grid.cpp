
class Solution {
public:
    bool valid(auto& grid, int sx, int sy, int ex, int ey) {
        unordered_map<int, int> mp;

        int totalSum = grid[sx][sy] + grid[ex][ey] + grid[sx + 1][sy + 1];
        // diagonal check
        int diagonalSum = grid[sx][ey] + grid[ex][sy] + grid[sx + 1][sy + 1];
        if (diagonalSum != totalSum)
            return false;

        // row wise
        for (int i = sx; i <= ex; i++) {
            int sum = 0;
            for (int j = sy; j <= ey; j++) {
                int e = grid[i][j];
                sum += e;
                mp[e]++;
                if (e >= 10 || e == 0)
                    return false;
            }
            if (sum != totalSum)
                return false;
        }

        // col wise
        for (int j = sy; j <= ey; j++) {
            int sum = 0;
            for (int i = sx; i <= ex; i++) {
                sum += grid[i][j];
                mp[grid[i][j]]++;
                if (grid[i][j] >= 10 || grid[i][j] == 0)
                    return false;
            }
            if (sum != totalSum)
                return false;
        }

        return mp.size() == 9;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        for (int sx = 0; sx < n - 2; sx++) {
            for (int sy = 0; sy < m - 2; sy++) {
                if (valid(grid, sx, sy, sx + 2, sy + 2))
                    count++;
            }
        }

        return count;
    }
};