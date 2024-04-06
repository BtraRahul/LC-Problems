class Solution {
    // "lee(t(c)o)de)"
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z')
                continue;
            if (c == ')' && st.size()&&st.top().first == '(') {
                    st.pop();
                
            } else
                st.push({c, i});
        }
        
        string final;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                final += s[i];
                continue;
            }

            if (st.size() && i == st.top().second) {
                st.pop();
            } else
                final += s[i];
        }
        reverse(final.begin(), final.end());
        return final;
    }
};