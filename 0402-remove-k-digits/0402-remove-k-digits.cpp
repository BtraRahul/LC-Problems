class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> q;

        for (char c : num) {
            while (k && q.size() && c < q.top()) {
                q.pop();
                k--;
            }

            if (c == '0' && q.empty())
                continue;
            q.push(c);
        }

        string final;
        while (k && q.size()) {
            q.pop();
            k--;
        }

        while (q.size()) {
            final += q.top();
            q.pop();
        }


        reverse(final.begin(), final.end());

        if (final.empty())
            return "0";
        return final;
    }
};