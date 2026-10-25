class Solution {
public:
   
    int solveusingmem(int n , vector<int> &dp){
        if(n == 0 || n == 1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = solveusingmem(n-1 , dp) + solveusingmem(n-2 , dp);
        return dp[n];
    }
    int fib(int n) {

        vector<int> dp(n+1 , -1);
        int ans = solveusingmem(n , dp);
        return ans;
    }
};
