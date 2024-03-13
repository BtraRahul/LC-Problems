class Solution {
public:
    int pivotInteger(int n) {
        for(int i=1;i<=n;i++){
            int  left=i*(i+1)/2+i*(i-1)/2;
            int right=n*(n+1)/2;
            
            if(left == right) return i;
            if(left > right) return -1;
        }
        
        return -1;
        
    }
};