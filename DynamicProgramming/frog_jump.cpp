class Solution {
  public:
    int solve(int index , vector<int> &heights , vector<int> &dp){
         if(index == 0){
             return 0;
         }
         if(dp[index] != -1){
             return dp[index];
         }
          int op1 = abs(heights[index] - heights[index -1 ]) + solve(index -1 , heights , dp);

          int op2 = INT_MAX;

          if(index > 1){
             op2 = abs(heights[index] - heights[index -2 ]) + solve(index -2 , heights , dp);
          }
          dp[index] = min(op1 , op2);
          return dp[index];
     }
     
    int minCost(vector<int>& height) {
        // Code here
        int size = height.size();
        vector<int>dp(size , -1);
        return solve(size -1 , height, dp);
    }
};
