class Solution {
public:
    int solveusingtab(string a , string b , int i , int j){
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j;
        }

        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
    
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = dp[i + 1][j + 1];
                } else {
                    int insert = 1 + dp[i][j + 1];
                    int remove = 1 + dp[i + 1][j];
                    int replace = 1 + dp[i + 1][j + 1];
                    ans = min(insert, min(remove, replace));
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
    
    int minDistance(string word1, string word2) {
        int i =0;
        int j =0;
        return solveusingtab(word1 , word2 , i ,j);
    }
};
