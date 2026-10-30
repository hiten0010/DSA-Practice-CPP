class Solution {
  public:
    int solveusingmemo(int n , int k , vector<int> &dp){
        if(n == 1){
            return k;
        }
        if(n == 2){
            return k*k;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        int same = solveusingmemo(n -2, k, dp) *(k-1);
        
        int diff = solveusingmemo(n -1, k , dp)*(k-1);
        
        dp[n] = same + diff;
        return dp[n];
    }
    int countWays(int n, int k) {
        // code here
        vector<int> dp(n+1 , -1);
        int ans = solveusingmemo(n, k , dp);
        return ans;
    }
};
