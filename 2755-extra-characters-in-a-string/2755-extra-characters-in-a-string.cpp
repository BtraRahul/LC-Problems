class Solution {
    vector<int> dp;
public:
    int helper(string &s, vector<string> & d,unordered_set<string>& st, int idx=0){
        if(idx >= s.size()) return 0;

        if(dp[idx]+1) return dp[idx];
        
        string temp="";
        int ans=s.size();
        for(int i=idx;i<s.size();i++){
            temp+=s[i];
            
            int count=temp.size();
            if(st.count(temp)) count=0;

            count+=helper(s,d,st,i+1);

            ans=min(ans, count);
        }

        return dp[idx]=ans;
    }
    int minExtraChar(string s, vector<string>& d) {
        unordered_set<string> st(d.begin(), d.end());

        int n=s.size();
        dp.resize(n+1, -1);
        return helper(s, d, st);
        
    }
};

// class Solution {
// public:
//     static bool cmp(string &a, string &b){
//         return a.size() < b.size();
//     }
//     int minExtraChar(string s, vector<string>& dictionary) {
//         if(s.size()==0) return 0;
//         sort(dictionary.rbegin(), dictionary.rend(), cmp);
//         cout<<s<<endl;
//         for(auto str: dictionary){
//             cout<<str<<" ";
//         }
//         cout<<endl;
//         cout<<endl;
//         for(int i=0;i<dictionary.size();i++){
//             string str=dictionary[i];
//             int idx=s.find(str);
//             if(idx==-1) continue;

//             while(idx!=-1){
//                 s.erase(idx, str.size());
//                 idx=s.find(str);
//             }
//             cout<<str<<" "<<s<<endl;
//         }

//         return s.size();
        
//     }
// };
// class Solution {
// public:
//     int minExtraChar(string s, vector<string>& dictionary) {
//         int max_val = s.length() + 1;
//         vector<int> dp(s.length() + 1, max_val);
//         dp[0] = 0;

//         unordered_set<string> dictionary_set(dictionary.begin(), dictionary.end());

//         for (int i = 1; i <= s.length(); ++i) {
//             dp[i] = dp[i - 1] + 1;
//             for (int l = 1; l <= i; ++l) {
//                 if (dictionary_set.find(s.substr(i - l, l)) != dictionary_set.end()) {
//                     dp[i] = min(dp[i], dp[i - l]);
//                 }
//             }
//         }
//         return dp.back();
//     }
// };