class Solution {
public:
    int solve(int start , int end , vector<int>& nums , vector<int> &dp){
        if(start > end ){
            return 0;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        int opt1 =nums[start] + solve(start +2, end , nums , dp);
        int opt2 = solve(start +1 , end, nums , dp);
        dp[start] = max(opt1 , opt2);
        return dp[start];
    }
    int rob(vector<int>& nums) {
        int end = nums.size();
        int start = 0;
        if(end ==0)return 0;
        if(end == 1)return nums[0];

        vector<int> dp1(end , -1);
        vector<int> dp2(end , -1);

        int case1 = solve(start , end -2 , nums , dp1);
        int case2 = solve(start +1 , end -1 , nums , dp2);

        int ans = max(case1 , case2);
        return ans;
    }
};
