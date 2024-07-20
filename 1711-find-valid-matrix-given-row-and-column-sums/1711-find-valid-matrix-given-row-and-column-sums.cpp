class Solution {
    // rowSum = [3,8], colSum = [4,7]
     // a b
     // c d
     //a+b=3
     //a+c=4
     //c+d=8
     //b+d=7
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), 0));
        for(int i=0;i<rowSum.size();i++){
            for(int j=0;j<colSum.size();j++){
                int req=min(rowSum[i], colSum[j]);

                ans[i][j]=req;

                rowSum[i]-=req;
                colSum[j]-=req;
            }
        }    

        return ans;
    }
};