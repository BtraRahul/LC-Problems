class Solution {
    vector<string> final;

public:
    void helper(int i,int j, string s=""){
        if(i<0 || j<0) return;
        if(i>j) return;

        if(i==0 && i==j)
        final.push_back(s);

        helper(i-1, j, s+'(');
        helper(i, j-1, s+')');


    }
    vector<string> generateParenthesis(int n) {
        helper(n, n);

        return final;
    }
};