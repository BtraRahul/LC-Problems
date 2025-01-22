/*
Conditions:
1. water cell have to 0
2. abs diff bet any 2 adjacent cells have to be at most 1
3. Directions: up, down, left, right

matrix[i][j] = 1 (+/-) [ m[i+1][j], m[i-1][j], m[i][j+1], m[i][j-1] ]
m[i][j] = 1 + min(m[i+1][j], m[i-1][j], m[i][j+1], m[i][j-1])


6 5 4 3
5 4 3 2
4 3 2 1
2 2 1 0

algo:
1. mark all land as 1, water as 0
2. start from water, bfs
3. move to all directions
4. m[i][j] = 1 + min(m[i+1][j], m[i-1][j], m[i][j+1], m[i][j-1])

[2,1,2,3,2,1,X,1]
[1,X,1,2,0,2,1,2]
[0,1,0,0,0,0,0,0]
[0,0,0,0,0,0,0,0]
[0,0,0,0,0,0,0,0]
[0,0,0,0,0,0,1,0]
[0,0,1,0,0,1,X,1]
[0,1,X,1,0,0,1,0]
*/

#define pii pair<int, int>
class Solution {
    int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isValid(int i, int j, int r, int c) {
        return (i >= 0) && (j >= 0) && (i < r) && (j < c);
    }

    int findMinAdjVal(int x, int y, auto& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int minVal = INT_MAX;

        for (int i = 0; i < 4; i++) {
            int newX = x + dxdy[i][0];
            int newY = y + dxdy[i][1];

            if (isValid(newX, newY, m, n) == false)
                continue;
            minVal = min(minVal, mat[newX][newY]);
        }

        return minVal;
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(isWater);
        queue<pii> q;
        map<pii, int> vis;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = INT_MAX;
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (q.size()) {
            auto [x, y] = q.front();
            // cout << x << "," << y << ": " << ans[x][y] << endl;
            q.pop();
            if (vis[{x, y}] == 1)
                continue;
            vis[{x, y}] = 1;

            if (isWater[x][y] == 1)
                ans[x][y] = 0;
            else {
                int minAdjVal = findMinAdjVal(x, y, ans);
                ans[x][y] = 1 + minAdjVal;
            }

            for (int i = 0; i < 4; i++) {
                int newX = x + dxdy[i][0];
                int newY = y + dxdy[i][1];

                if (isValid(newX, newY, m, n) == false || vis[{newX, newY}])
                    continue;
                q.push({newX, newY});
            }
        }

        return ans;
    }
};