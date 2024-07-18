class Solution {
public:
    vector<pair<int, int>> dxdy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();

        int val = image[sr][sc];

        queue<pair<int, int>> q;
        map<pair<int, int>, int> vis;
        q.push({sr, sc});

        image[sr][sc]=color;
        while (q.size()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            image[x][y]=color;
            for (auto coor : dxdy) {
                int i = x + coor.first;
                int j = y + coor.second;

                if (i >= 0 && i < m && j >= 0 && j < n && image[i][j] == val && !vis[{i,j}]) {
                    vis[{i,j}]=1;
                    q.push({i, j});
                }
            }
        }

        return image;
    }
};