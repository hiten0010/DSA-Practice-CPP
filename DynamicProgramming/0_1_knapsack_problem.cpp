class Solution {
  public:
    int solveusingrec(int W, int n, vector<int> &val, vector<int> &wt , int index , vector<vector<int>> &dp){
        if(index == n || W == 0){
            return 0;
        }
        if(dp[index][W] != -1){
            return dp[index][W];
        }
        int take = 0;
        if(wt[index] <= W){
            take = val[index] + solveusingrec(W - wt[index] , n , val , wt, index +1 , dp);
        }
        int nottake = solveusingrec(W  , n , val , wt, index +1 , dp);
        return dp[index][W] = max(take , nottake);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        int index = 0;
        vector<vector<int>> dp(n , vector<int>(W+1 , -1));
        int ans = solveusingrec(W , n , val , wt, index , dp);
        return ans;
    }
};
