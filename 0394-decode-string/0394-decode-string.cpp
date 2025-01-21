/*
3[a]2[bc]

3*(a) + 2*(bc) = aaabcbc

3[a2[c]] = 3*(a+2*(c))

3[a2[c]b]de = 3*(a+2*c+b)+d+e

3
[a2[c]b]


algo(stacks):
1. if number      : push into stack
2. if alphabet    : add to temp str
3. if char == '[' : add tempstr to stack
4. if char == ']' : merge all the strings in stack, and multiply it as well, put
                    final str in stack again
*/
class Solution {
    // string helper(string str, int i) {
    //     if (i >= str.size())
    //         return "";
    //     string s, num;

    //     for (; i < str.size(); i++) {
    //         if (str[i] >= 'a' && str[i] <= 'z')
    //             s += str[i];
    //         else if (str[i] >= '1' && str[i] < '9') {
    //             num += str[i];
    //         } else if (str[i] == '[') {
    //             int frq = stoi(num);
    //             num = "";
    //         }
    //     }
    // }

public:
    string decodeString(string s) {
        stack<string> st;
        string final, temp, num;

        for (char c : s) {
            if (isalpha(c)) {
                temp += c;
            } else if (isdigit(c)) {
                num += c;
            } else if (c == '[') {
                if (temp.size()) {
                    st.push(temp);
                    cout << temp << " ";
                }
                st.push(num);
                cout << num << endl;
                temp = num = "";
            } else if (c == ']') {
                st.push(temp);
                temp = "";
                string tempFinal;
                // accumulate the string
                while (!isdigit(st.top()[0])) {
                    string prev = st.top();
                    st.pop();
                    tempFinal = prev + tempFinal;
                }
                cout << tempFinal;

                int frq = stoi(st.top());
                st.pop();
                string newTemp;
                while (frq--) {
                    newTemp += tempFinal;
                }

                st.push(newTemp);
            }
        }

        while (st.size()) {
            string prev = st.top();
            st.pop();
            final = prev + final;
        }

        final += temp;

        return final;
    }
};