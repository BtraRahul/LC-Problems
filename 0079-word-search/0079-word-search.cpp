class Solution {
    vector<vector<int>> vis;

public:
    bool inline valid(int n, int m, int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int dxdy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool helper(auto& b, int r, int c, string w, int idx) {
        if (idx >= w.size())
            return true;

        int n = b.size();
        int m = b[0].size();
        bool ans = false;

        for (int i = 0; i < 4; i++) {
            int new_r = r + dxdy[i][0];
            int new_c = c + dxdy[i][1];

            if (valid(n, m, new_r, new_c) && vis[new_r][new_c] == 0 &&
                w[idx] == b[new_r][new_c]) {
                // cout << new_r << " " << new_c << "\n";
                vis[new_r][new_c] = 1;
                ans = ans | helper(b, new_r, new_c, w, idx + 1);
                vis[new_r][new_c] = 0;
                if (ans)
                    return true;
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0)
            return true;

        unordered_set<char> mp;
        for (char c : word)
            mp.insert(c);

        for (auto row : board)
            for (auto c : row)
                mp.erase(c);

        if (mp.size())
            return false;
        int n = board.size(), m = board[0].size();

        vis.resize(n, vector<int>(m, 0));

        bool ans = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    // cout<<i<<" "<<j<<endl;
                    vis[i][j] = 1;
                    ans = ans | helper(board, i, j, word, 1);
                    vis[i][j] = 0;
                    if (ans)
                        return true;
                }
            }
        }

        return ans;
    }
};