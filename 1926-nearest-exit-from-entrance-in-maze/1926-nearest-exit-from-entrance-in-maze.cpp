#include <vector>
#include <queue>

using namespace std;

class Solution {
    int dxdy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    bool valid(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool exit(int i, int j, int m, int n) {
        return (i == 0 || i == m - 1 || j == 0 || j == n - 1);
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int sx = entrance[0], sy = entrance[1];

        queue<pair<pair<int, int>, int>> q;

        q.push({{sx, sy}, 0});
        maze[sx][sy] = '+'; // Mark the entrance as visited

        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            int dist = f.second;
            int x = f.first.first;
            int y = f.first.second;

            for (int i = 0; i < 4; i++) {
                int newX = x + dxdy[i][0];
                int newY = y + dxdy[i][1];

                if (!valid(newX, newY, m, n) || maze[newX][newY] == '+')
                    continue;

                if (exit(newX, newY, m, n) && !(newX == sx && newY == sy))
                    return dist + 1;

                q.push({{newX, newY}, dist + 1});
                maze[newX][newY] = '+'; // Mark the cell as visited
            }
        }

        return -1;
    }
};
