class Solution {
    vector<vector<int>> vis;
    vector<int> ans;
public:
    int dxdy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

    bool isvalid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void helper(auto & matrix, int i, int j, int k=0){
        int n=matrix.size();
        int m=matrix[0].size();
        
        ans.push_back(matrix[i][j]);

        if(!isvalid(i+dxdy[k][0],j+dxdy[k][1], n, m) || vis[i+dxdy[k][0]][j+dxdy[k][1]] == 1) k=(k+1)%4;

        int newx=i+dxdy[k][0];
        int newy=j+dxdy[k][1];

        if(isvalid(newx, newy, n, m) && vis[newx][newy]==0){
            vis[newx][newy]=1;
            helper(matrix, newx, newy, k);
        }

    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vis.resize(n, vector<int>(m, 0));
        vis[0][0]=1;
        helper(matrix, 0, 0);

        return ans;
    }
};