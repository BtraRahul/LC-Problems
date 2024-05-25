class Solution {
    vector<string> final;

public:
    // cats and dog .
    // cat sand dog .
    void helper(string s, int si, unordered_set<string>& wds, string str = "",
                string t = "") {
        if (si == s.size()) {
            if (t.empty()) {
                final.push_back(str);
            } else {
                if (wds.find(t) != wds.end()) {
                    str += ' ' + t;
                    final.push_back(str);
                } else
                    return;
            }
        }
        // cout << t << " ";

        // // count
        // if (wds.count(t)) {
        //     helper(s, i, wds, str + ' ' + t);
        // }

        // // dont
        // helper(s, i + 1, wds, str, t + s[i]);
        string temp;
        for (int i = si; i < s.size(); i++) {
            // string temp = s.substr(si, i - si + 1);
            temp += s[i];
            if (wds.count(temp))
                if (str.empty())
                    helper(s, i + 1, wds, str + temp);
                else
                    helper(s, i + 1, wds, str + ' ' + temp);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty())
            return {};

        unordered_set<string> words(wordDict.begin(), wordDict.end());
        helper(s, 0, words);
        cout << endl << final.size() << endl;
        return final;
    }
};