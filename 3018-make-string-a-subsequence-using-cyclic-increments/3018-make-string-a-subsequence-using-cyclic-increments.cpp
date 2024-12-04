class Solution {
public:
    char increment(char a){
        if(a=='z') return 'a';
        return a+1;
    }
    char decrement(char a){
        if(a=='a') return 'z';
        return a-1;
    }
    bool canMakeSubsequence(string str1, string str2) {
        int i=0, j=0;
        
        while(i<str1.size() && j<str2.size()){
            char a=str1[i];
            char b=str2[j];
            if(a==b || increment(a) == b){
                i++, j++;
                continue;
            }
            
            i++;
        }
        
        if(j==str2.size()) return true;
        return false;
        
    }
};