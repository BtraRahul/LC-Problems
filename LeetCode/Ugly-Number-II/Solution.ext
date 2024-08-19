// #define pb push_back
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         if (n <= 6)
//             return n;
//         map<int, int> mp;
//         vector<int> v2, v3, v5;
//         v2.pb(2);
//         v3.pb(3);
//         v5.pb(5);

//         int i = 0, j = 0, k = 0;

//         int t = 1;
//         while (t < n) {
//             if (v2[i] < v3[j] && v2[i] < v5[k]) {
//                 int num = v2[i];
//                 if (mp.find(num * 2) == mp.end())
//                     v2.pb(num * 2);
//                 if (mp.find(num * 3) == mp.end())
//                     v3.pb(num * 3);
//                 if (mp.find(num * 5) == mp.end())
//                     v5.pb(num * 5);
//                 else
//                     continue;
//                 t++; i++;
//             } else if (v3[j] < v2[i] && v3[j] < v5[k]) {
//                 int num = v3[j];
//                 if (mp.find(num * 2) == mp.end())
//                     v2.pb(num * 2);
//                 if (mp.find(num * 3) == mp.end())
//                     v3.pb(num * 3);
//                 if (mp.find(num * 5) == mp.end())
//                     v5.pb(num * 5);
//                 else
//                     continue;
//                 t++;
//             } else if (v5[k] < v3[j] && v5[k] < v2[i]) {
//                 int num = v5[k];
//                 if (mp.find(num * 2) == mp.end())
//                     v2.pb(num * 2);
//                 if (mp.find(num * 3) == mp.end())
//                     v3.pb(num * 3);
//                 if (mp.find(num * 5) == mp.end())
//                     v5.pb(num * 5);
//                 else
//                     continue;
//                 t++;
//             }
//         }

//         // mp.push(2);
//         //     // mp.push(3);
//         //     // mp.push(5);
//         //     mp[1] = 1;

//         //     int t = 4;

//         //     for (auto p : mp) {
//         //         // int num = mp.begin()->first;
//         //         int num = p.first;
//         //         mp[num * 2] = 1;

//         //         num = p.first;
//         //         mp[num * 3] = 1;

//         //         num = p.first;
//         //         mp[num * 5] = 1;
//         //         cout << mp.size() << ": "<<num<<": ";
//         //         cout << num * 2 << " " << num * 3 << " " << num * 5 << endl;
//         //         if (mp.size() >= n+1)
//         //             break;
//         //     }

//         //     return mp.end()->first;
//         // }
//     };
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        return nthUglyNumberRecursive(dp, n, 1, 0, 0, 0);
    }

private:
    int nthUglyNumberRecursive(vector<int>& dp, int n, int i, int p1, int p2, int p3) {
        if (i == n) {
            return dp[n - 1];
        }

        int twoMultiple = dp[p1] * 2;
        int threeMultiple = dp[p2] * 3;
        int fiveMultiple = dp[p3] * 5;

        dp[i] = min(twoMultiple, min(threeMultiple, fiveMultiple));

        int nextP1 = (dp[i] == twoMultiple) ? p1 + 1 : p1;
        int nextP2 = (dp[i] == threeMultiple) ? p2 + 1 : p2;
        int nextP3 = (dp[i] == fiveMultiple) ? p3 + 1 : p3;

        return nthUglyNumberRecursive(dp, n, i + 1, nextP1, nextP2, nextP3);
    }
};