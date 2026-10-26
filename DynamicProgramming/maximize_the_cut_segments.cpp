class Solution {
  public:
  int solveusingrec(int n, int x, int y, int z , vector<int> & dp){
        if(n == 0){
            return 0;
        }
        if(n < 0){
            return INT_MIN;
        }
        if(dp[n] != INT_MIN){
            return dp[n];
        }
        
        int op1 = 1 + solveusingrec(n - x, x, y, z , dp);
        int op2 = 1 + solveusingrec(n - y, x, y, z , dp);
        int op3 = 1 + solveusingrec(n - z, x, y, z , dp);
        
        dp[n] = max(op1 , max(op2 , op3));
        return dp[n];
  }
    int maximizeCuts(int n, int x, int y, int z) {
        // code here
        vector<int> dp(n+1 , INT_MIN);
        int ans = solveusingrec(n , x , y ,z , dp);
        if( ans < 0){
            return 0;
        }
        return ans;
        
    }
};
