// class Solution {
// public:
//     // b-a
//     //  (1+(4+5+2)-3)+(6+8)
//     //  st: (+(++)-)+(+)
//     //  nm: 1452368
//     //  st: (+-)+(+)
//     //  nm: 111368
//     //  st: +
//     //  nm: 9 14

//     // " 2-1 + 2 " ===  2 + -1 + 2

//     // stri
//     int calculate(string s) {

//         // "1 + 1"
//         stack<char> st;
//         stack<int> nm;

//         string number;
//         char prev = '0';
//         for (char c : s) {
//             if (c == ' ')
//                 continue;
//             if (prev == '(' && (c == '+' || c == '-'))
//                 number += '0';
//             prev = c;
//             number += c;
//         }

//         s = number;
//         int i = 0;
//         int ans = 0;
//         cout << s << endl;
//         while (i < s.size()) {

//             if (s[i] >= '0' && s[i] <= '9') {

//                 string temp;
//                 while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
//                     temp += s[i++];
//                 }
//                 int num = stoi(temp);
//                 if (st.size() && st.top() == '-') {
//                     st.pop();
//                     if (nm.size())
//                         st.push('+');
//                     nm.push(-num);
//                 } else
//                     nm.push(num);
//                 cout << nm.top() << " ";

//                 continue;
//             }
//             if (i >= s.size()) {
//                 break;
//             }
//             if (s[i] == ')') {

//                 while (st.top() != '(') {

//                     int a = nm.top();
//                     nm.pop();
//                     int b = nm.top();
//                     nm.pop();

//                     char sym = st.top();
//                     st.pop();

//                     if (sym == '+')
//                         nm.push(b + a);
//                     else
//                         nm.push(b - a);
//                 }

//                 st.pop();
//             } else {
//                 // if (i > 0 && (s[i] == '+' || s[i] == '-') && s[i - 1] == '(')
//                 //     nm.push(0);
//                 st.push(s[i]);
//             }

//             i++;
//             if (nm.size())
//                 ans = nm.top();
//         }
//         if (nm.empty())
//             return ans;
//         if (nm.size())
//             ans = nm.top();
//         if (st.size() == 0)
//             return ans;

//         if (st.size() == 1 && st.top() == '-')
//             return -nm.top();
//         while (st.size()) {
//             if (nm.empty())
//                 return ans;
//             int a = nm.top();
//             nm.pop();
//             int b = nm.top();
//             nm.pop();

//             char sym = st.top();
//             st.pop();

//             if (sym == '+')
//                 nm.push(b + a);
//             else
//                 nm.push(b - a);

//             ans = nm.top();
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return helper(s, i);
    }

    int helper(string& s, int& i) {
        int ans = 0, interim = 0; 
        long long num = 0;
        char op = '+';
        while (i < s.size()) {
            if (isdigit(s[i])) 
            {
                num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                
                if (op == '+' || op == '-') 
                {
                    ans += interim;
                    if(op == '-') interim= -1*num;
                    else interim = num;
                } 
                else if (op == '*') 
                {
                    interim *= num;
                } 
                else if (op == '/') 
                {
                    interim /= num;
                }
            } 
            else if (s[i] == '(') 
            {
                i++; // skip the '('
                num = helper(s, i);
                
                if (op == '+' || op == '-') 
                {
                    ans += interim;
                    if(op == '-') interim= -1*num;
                    else interim = num;
                } 
                else if (op == '*') 
                {
                    interim *= num;
                } 
                else if (op == '/') 
                {
                    interim /= num;
                }
            } 
            else if (s[i] == ')') 
            {
                i++; // skip the ')'
                break; // exit the current level of recursion
            } 
            else 
            {
                if (s[i] != ' ') op = s[i];
                i++;
            }
        }
        ans += interim;
        return ans;
    }
};