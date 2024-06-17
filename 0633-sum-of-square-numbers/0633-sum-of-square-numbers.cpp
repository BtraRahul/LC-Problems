class Solution {
public:
    bool judgeSquareSum(int c) {
        if (!c)
            return 1;

        for (int i = 0; i <= sqrt(c); i++) {
            double ans = c - i * i;
            // cout<<i*i<<" "<<sqrt(ans)<<endl;
            if (sqrt(ans) == (long long)(sqrt(ans)))
                return true;
        }
        // cout<<INT_MAX;
        return false;
    }
};