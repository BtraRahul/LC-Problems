class Solution {
    // "2908305" ->
    // 00 -> 29'0'83'0'5  remove 8,3,5 : ans = 3
    // 25 -> '2'90830'5' ans: 4
    // 50 -> inf
    // 75 -> inf
public:
    // 00,25,50,75
    int helper(string search, string num) {
        int i = -1, j = -1;

        for (int idx = num.size() - 1; idx >= 0; idx--) {
            if (num[idx] == search[1]) {
                j = idx;
                break;
            }
        }

        if (j == -1)
            return INT_MAX;

        for (int idx = j; idx >= 0; idx--) {
            if (num[idx] == search[0]) {
                if (i == -1) {
                    i = idx;
                } else if (i == j) {
                    i = idx;
                    break;
                }
            }
        }
        cout << search << " " << i << " " << j << endl;

        if(i==j) return num.size()-1;
        return (i == -1) ? INT_MAX : (num.size() - i - 2);
    }
    int minimumOperations(string num) {
        int ans = INT_MAX;

        if (num.size() ==1){
            if(num=="0") return 0;
            return 1;
        }
        // 00
        ans = min(ans, helper("00", num));

        // 25
        ans = min(ans, helper("25", num));

        // 50
        ans = min(ans, helper("50", num));

        //   75
        ans = min(ans, helper("75", num));

        return ans == INT_MAX ? num.size() : ans;
    }
};