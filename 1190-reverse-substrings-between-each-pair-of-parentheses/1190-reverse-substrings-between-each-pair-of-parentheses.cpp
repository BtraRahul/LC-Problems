class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                string str;
                while (st.top() != '(') {
                    str += st.top();
                    st.pop();
                }
                st.pop();
                for (int i = 0; i < str.size(); i++)
                    st.push(str[i]);
            } else {
                st.push(s[i]);
            }
        }
        string final;

        while (st.size()) {
            if (st.top() != '(')
                final += st.top();
            st.pop();
        }
        // cout << st.size();
        reverse(final.begin(), final.end());
        return final;
    }
};