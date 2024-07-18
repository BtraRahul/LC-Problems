class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
    int orangesRotting(vector<vector<int>>& grid) {

        queue<vector<int>> q; //{i,j, time}

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j, 0});
            }
        }

        int final = 0;
        while (q.size()) {
            vector<int> f = q.front();
            q.pop();
            int i = f[0];
            int j = f[1];
            int t = f[2];

            final = max(final, t);

            // 4 directions: up, down, left, right
            if (isValid(i + 1, j, grid) && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                q.push({i + 1, j, t + 1});
            }

            if (isValid(i, j + 1, grid) && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push({i, j + 1, t + 1});
            }

            if (isValid(i - 1, j, grid) && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                q.push({i - 1, j, t + 1});
            }

            if (isValid(i, j - 1, grid) && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push({i, j - 1, t + 1});
            }
        }

        for(auto row: grid){
            for(int e: row) if(e==1) return -1;
        }


        return final;
    }
};