class Solution {
public:
    bool valid(int n) {
        int r = n % 10;
        n /= 10;

        while (n) {
            if (n % 10 > r)
                return false;
            r = n % 10;
            n /= 10;
        }

        return true;
    }
    int monotoneIncreasingDigits(int n) {
        // if (n < 10)
        //     return n;
        // else if (n == 10)
        //     return 9;

        int temp = n;
        int add = 0;
        while (temp) {
            temp /= 10;
            add = add * 10 + 1;
        }

        int maxAns = 0;
        cout << temp << " " << add << endl;
        while (temp < n) {
            if (temp + add <= n) {
                if (temp % 10 == 9)
                    temp++;
                temp += add;
                if(temp>n) continue;
                if (valid(temp))
                    maxAns = max(maxAns, temp);
            } else {
                add /= 10;
            }
        }

        return maxAns;
    }
};