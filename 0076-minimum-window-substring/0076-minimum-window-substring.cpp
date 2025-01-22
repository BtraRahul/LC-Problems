class Solution {

public:
string minWindow(string s, string t) {
    unordered_map<char, int> target, window;
    for (char c : t) {
        target[c]++;
    }

    int required = target.size();
    int formed = 0;
    int left = 0, right = 0;
    int minLen = INT_MAX;
    pair<int, int> result = {-1, -1};

    while (right < s.length()) {
        char c = s[right];
        window[c]++;

        if (target.find(c) != target.end() && window[c] == target[c]) {
            formed++;
        }

        while (formed == required && left <= right) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                result = {left, right};
            }

            char d = s[left];
            window[d]--;

            if (target.find(d) != target.end() && window[d] < target[d]) {
                formed--;
            }

            left++;
        }

        right++;
    }

    if (result.first == -1) {
        return "";
    } else {
        return s.substr(result.first, result.second - result.first + 1);
    }
}

    // pair<int, int> curr = {0, INT_MAX};
    // bool valid(unordered_map<char, int>& sp, unordered_map<char, int>& tp) {
    //     for (auto ele : tp) {
    //         char c = ele.first;
    //         cout << c << " " << tp.at(c) << " " << sp[c] << endl;

    //         if (sp.find(c) == sp.end() || tp.at(c) > sp[c])
    //             return false;
    //     }

    //     return true;
    // }

    // string minWindow(string s, string t) {
    //     unordered_map<char, int> sp, tp;
    //     if (s == t)
    //         return s;

    //     for (char c : t) {
    //         tp[c]++;
    //     }

    //     int n = s.size();
    //     int i = 0, j = 0;
    //     sp[s[j]]++;

    //     while (i <= j && j < n) {

    //         cout << endl << i << " " << j << endl;
    //         if (valid(sp, tp)) {
    //             if (j - i < curr.second - curr.first)
    //                 curr = {i, j};

    //             char d = s[i];
    //             sp[d]--;
    //             if (sp[d] == 0)
    //                 sp.erase(d);

    //             i++;
    //         } else {
    //             j++;
    //             char c = s[j];
    //             sp[c]++;
    //         }
    //     }

    //     if (curr.second == INT_MAX)
    //         return "";

    //     return s.substr(curr.first, curr.second - curr.first + 1);
    // }
};