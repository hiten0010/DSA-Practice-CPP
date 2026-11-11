class Solution {
public:
   
    int solvetab(vector<int> & nums){
        int n = nums.size();
        vector<int> dp(n +2 , 0);

        for(int i =n-1 ; i>=0 ; i--){
            int op1 = nums[i] + dp[i+2];
            int op2 = dp[i+1];
            dp[i] = max(op1 , op2);
        }
        return dp[0];
    }
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        return solvetab(nums);
    }
};
