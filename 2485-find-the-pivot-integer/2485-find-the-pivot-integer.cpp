class Solution {
public:
    int pivotInteger(int n) {
//         for(int i=1;i<=n;i++){
//             int  left=i*(i+1)/2+i*(i-1)/2;
//             int right=n*(n+1)/2;
            
//             if(left == right) return i;
//             if(left > right) return -1;
//         }
        
        
        float final = sqrt((n*(n+1))/2);
        
        if((int)final == final) return final;
        
        return -1;
        
    }
};


// (i*i + "i" + i*i-"i" )/2 = i*i;
// i*i = n*(n+1)/2;
// i= sqrt(n*(n+1)/2);