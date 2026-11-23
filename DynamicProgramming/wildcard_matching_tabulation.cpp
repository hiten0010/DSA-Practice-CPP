class Solution {
public:
   
   bool solvetab(string str , string pat){
      int n = str.size();
      int m = pat.size();
      vector<vector<int>> dp(n +1, vector<int>(m+1, 0));
      dp[0][0] = true;

      for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int a = 1; a <= j; a++) {
                if (pat[a - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pat[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
   }
    bool wildCard(string str, string pat) {    
        return solvetab(str , pat);
    }
};
