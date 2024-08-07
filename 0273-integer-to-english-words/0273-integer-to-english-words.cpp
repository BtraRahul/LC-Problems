class Solution {
    unordered_map<int, string> mp;
    // 1234567 -> 1 234 567
    // 2147483647 -> 2 147 483 647
    //
    // 7
    // 60
    // 500
    // 34000
    // 12
public:
    Solution() {
        mp[0] = "Zero";
        mp[1] = "One";
        mp[2] = "Two";
        mp[3] = "Three";
        mp[4] = "Four";
        mp[5] = "Five";
        mp[6] = "Six";
        mp[7] = "Seven";
        mp[8] = "Eight";
        mp[9] = "Nine";
        mp[10] = "Ten";
        mp[11] = "Eleven";
        mp[12] = "Twelve";
        mp[13] = "Thirteen";
        mp[14] = "Fourteen";
        mp[15] = "Fifteen";
        mp[16] = "Sixteen";
        mp[17] = "Seventeen";
        mp[18] = "Eighteen";
        mp[19] = "Nineteen";
        mp[20] = "Twenty";
        mp[30] = "Thirty";
        mp[40] = "Forty";
        mp[50] = "Fifty";
        mp[60] = "Sixty";
        mp[70] = "Seventy";
        mp[80] = "Eighty";
        mp[90] = "Ninety";
    }

    string numToThreeDigits(int num) {
        if (num == 0)
            return mp[0];

        string result;

        if (num >= 100) {
            result += mp[num / 100] + " Hundred";
            num %= 100;
            if (num > 0)
                result += " ";
        }

        if (num >= 20) {
            result += mp[(num / 10) * 10];
            num %= 10;
            if (num > 0)
                result += " ";
        } else if (num >= 10) {
            result += mp[num];
            num = 0;
        }

        if (num > 0) {
            result += mp[num];
        }

        return result;
    }
    string numberToWords(int num) {
        if(!num) return "Zero";
        vector<string> v;
        v.push_back("");
        v.push_back("Thousand");
        v.push_back("Million");
        v.push_back("Billion");

        int i = 0;
        string final;
        while (num) {
            final = numToThreeDigits(num % 1000) + " " + v[i++] + " " + final;
            num /= 1000;
        }

        while(final.back() == ' ') final.pop_back();
        return final;
    }
};