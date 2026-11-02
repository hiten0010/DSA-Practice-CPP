class Solution {
public:
    int solveusingmemo(int p , int q , string& text1, string &text2 , vector<vector<int>> &dp){
        int n = text1.length();
        int m = text2.length();

        if(p == n || q == m){
           return 0;
        }
        if(dp[p][q] != -1){
            return dp[p][q];
        }
        if(text1[p] == text2[q]){
            dp[p][q] =  1 + solveusingmemo(p+1 , q+1 ,text1 , text2 , dp);
        }
        else{
            dp[p][q] =  max(solveusingmemo(p +1 , q ,text1 , text2 , dp), solveusingmemo(p , q+1 ,text1 , text2 , dp));
        }
        return dp[p][q];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1 ,vector<int>(m+1 , -1));
        return solveusingmemo(0 , 0 ,text1 , text2, dp );
    }
};
