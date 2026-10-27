class Solution {
public:
    int solveusingmemo(vector<int> &nums , int size , int index , vector<int>& dp){
        if(index >= size){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int op1 = nums[index] + solveusingmemo(nums , size , index + 2 , dp);
        int op2 = solveusingmemo(nums , size , index +1 , dp);
        dp[index] = max(op1 , op2);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size+1 , -1);
        int index = 0;
        int ans = solveusingmemo(nums , size , index , dp);
        return ans;
    }
};
