class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int i = 1, ans = 0;
        int tb = blue, tr = red;

        while (tb >= 0 && tr >= 0) {
            tb -= i;
            i++;

            if (tb >= 0)
                ans++;
            else
                break;

            tr -= i;
            i++;

            if (tr >= 0)
                ans++;
            else
                break;
        }

        int newAns = ans;
        ans = 0;
        tb = blue, tr = red;
        i = 1;

        while (tb >= 0 && tr >= 0) {

            tr -= i;
            i++;

            if (tr >= 0)
                ans++;
            else
                break;


            tb -= i;
            i++;

            if (tb >= 0)
                ans++;
            else
                break;
        }
        return max(ans, newAns);
    }
};