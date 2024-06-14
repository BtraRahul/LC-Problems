class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {  
	 // Arrays to track trust given and received
        vector<int> trusting(n + 1, 0);   
        vector<int> trusted(n + 1, 0);     
        for (auto i : trust) {                    // Count trust relationships
            trusting[i[0]]++;                    // Increment trust given
            trusted[i[1]]++;                    // Increment trust received
        }
        int ans = -1;                           
                       
        for (int i = 1; i <= n; i++)          
        
            if (trusting[i] == 0 && trusted[i] == n - 1){ 
                ans = i;            }
        return ans;              
    }
};