class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while (a || b || c) {
            int x = a | b;

            if ((c & 1) == 0) {
                if (a & 1)
                    count++;
                if (b & 1)
                    count++;
            } else if ((x & 1) == 0)
                count++;

            // cout << (x & 1) << " " << (c & 1) << endl;
            a = a >> 1, b = b >> 1, c = c >> 1;
        }

        return count;
    }
};