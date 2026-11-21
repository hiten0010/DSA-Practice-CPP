class Solution {
public:
   int solve(int i , int j ,const string &s ,vector<vector<int>> & dp){
       if(i > j){
        return 0;
       }

       if(i == j){
        return 1;
       }

       if(dp[i][j] != -1){
        return dp[i][j];
       }

       if(s[i] == s[j]){
        dp[i][j] = 1 + solve(i +1 , j , s , dp) + solve( i , j-1 , s , dp);
       }
       else{
        dp[i][j] = solve(i +1 , j , s , dp) + solve( i , j-1 , s , dp) - solve(i +1 , j -1, s , dp);
       }
       return dp[i][j];
   }
    int countPalSubseq(const string& s) {
        // Your code goes here
        int n = s.length();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return solve(0, n-1 , s , dp);
    }
};
