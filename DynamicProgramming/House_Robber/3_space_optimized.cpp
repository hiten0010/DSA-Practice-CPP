class Solution {
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if( n == 0){
            return 0;
        }
        int prev = 0 ;
        int curr = nums[0];
        int ans = curr;
        for(int i = 1 ; i<n ; i++){
            int op1 = nums[i] + prev;
            int op2 = curr;
            
            ans = max(op1 , op2);
            prev = curr;
            curr = ans;
        }
        return ans;
    }
};
