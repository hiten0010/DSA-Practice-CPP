class Solution {
public:
   bool solve(int idx, string& s, unordered_set<string>& st, vector<int>& dp) {
        int n = s.size();
        if (idx == n) return true;
        if (dp[idx] != -1) return dp[idx];

        for (int j = idx; j < n; j++) {
            string temp = s.substr(idx, j - idx + 1);
            if (st.count(temp) && solve(j + 1, s, st, dp)) {
                return dp[idx] = 1;
          }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // Your code goes here
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(0, s, st, dp);
    }
};
