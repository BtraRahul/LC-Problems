class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mapp;
        int n = s.length();
        for (int i = 0; i < s.length(); ++i) {
            string current = ""; // Reset substring for each starting point
            for (int j = i; j < s.length(); ++j) {
                current += s[j]; // Build substring
                if (current[0] != s[j])
                    break;
                mapp[current]++; // Add to map or increment count
            }
        }
        int final = -1;
        for (auto& p : mapp) {
            if (p.second >= 3) {
                final = max(final, (int)p.first.length());
            }
        }
        if (final > 0) {
            return final;
        }
        return -1;
    }
};