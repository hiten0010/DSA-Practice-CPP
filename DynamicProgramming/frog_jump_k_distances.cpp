#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int solve(vector<int>& heights, int k , int index ,vector<int>& dp){
        if(index == 0){
            return 0;
        }
        if(dp[index] != -1) {
           return dp[index];
        }
        int mini = INT_MAX;
        for(int i =1 ; i <=k ; i++){
            if(index - i >= 0){
                int jump = abs(heights[index] - heights[index - i]) + solve(heights , k ,index -i, dp);
                mini = min(mini , jump);
            }
        }
        dp[index] = mini;
        return dp[index];
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n , -1);
        return solve(heights , k ,n-1, dp);
    }
};
int main(){
    vector<int> heights = {10, 5, 20, 0, 15};
    int k = 2;
    Solution obj;
    int ans = obj.frogJump(heights , k);
    cout<<"The Minimum number of Jumps are : "<<ans<<endl;
    return 0;
}
