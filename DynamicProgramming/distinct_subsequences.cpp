class Solution{
  public: 
  int mode = 1e9 + 7;
  int solve(int i , int j , string s, string t , vector<vector<int>> & dp){
    // base case
    if(j ==0) return 1;
    if( i == 0) return 0;
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i-1] == t[j-1]){
        dp[i][j] = (solve(i -1 ,j-1 , s , t, dp) + solve(i -1 ,j , s , t, dp)) % mode;
    }
    else{
        dp[i][j] = solve(i -1 ,j , s , t, dp) % mode;
    }
    return dp[i][j];
  }
  int distinctSubsequences(string s, string t){
	   int n = s.size();
       int m = t.size();

       vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
       
       return solve(n ,m , s , t, dp);
	}
};
