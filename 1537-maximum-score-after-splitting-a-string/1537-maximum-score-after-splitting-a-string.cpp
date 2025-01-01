class Solution {
public:
    int maxScore(string s) {
        int ans=0;

        int left=0, right=0;
        for(char c: s){
            if(c=='1') right++;
        }

        int i=0;
        while(i<s.size()-1){
            if(s[i]=='0') left++;
            if(s[i]=='1') right--;

            ans=max(ans, left+right);

            i++;
        }

        return ans;
        
    }
};