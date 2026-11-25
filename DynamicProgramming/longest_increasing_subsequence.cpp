class Solution {
public:
    int solveusingmemo(int prev , int curr , vector<int> & nums , vector<vector<int>> & dp){
        int n = nums.size();
        if(curr == n){
            return 0;
        }
        if(dp[curr][prev +1] != -1){
            return dp[curr][prev +1];
        }
        int include = 0;

        if( prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveusingmemo( curr , curr + 1 ,nums , dp);
        }

        int exclude = solveusingmemo( prev , curr + 1 ,nums , dp);
        dp[curr][prev+1] = max(include , exclude);

        return dp[curr][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n ,vector<int>(n+1 , -1));
        return solveusingmemo( -1 , 0 ,nums , dp);
    }
};
