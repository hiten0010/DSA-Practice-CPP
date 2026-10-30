class Solution {
  public:
    
    int solveusingtabulation(int n , int k){
        vector<int> dp(n+1 , -1);
        dp[1] = k;
        dp[2] = k*k;
        
        for(int i = 3; i<= n ; i++){
            dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
        }
        return dp[n];
    }
   
    int countWays(int n, int k) {
        // code here
        int ans = solveusingtabulation(n, k);
        return ans;
    }
};
