class Solution{
	public: 
    int solve(int i , int j , string a , string b , vector<vector<int>> &dp){
        if(i < 0 || j < 0){
           return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(a[i] == b[j]){
            dp[i][j] = 1 + solve(i-1 ,j-1, a , b , dp);
        }
        else{
            dp[i][j] = max(solve(i-1 ,j, a , b , dp) , solve(i ,j-1, a , b, dp));
        }
        return dp[i][j];
    }
    int minOperations(string str1, string str2){ 
        int n = str1.length();
        int m = str2.length();
	    vector<vector<int>> dp(n , vector<int>(m, -1));
        int ans = solve(n-1 ,m-1, str1 , str2 , dp);

        int del = n - ans;
        int in = m - ans;
        return del + in;
	} 
};
