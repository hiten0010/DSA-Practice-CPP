class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        
        int prev2 = 0;
        int prev1 = arr[0];
        
        for (int i = 1; i < n; i++) {
            int take = arr[i] + prev2;
            int notTake = 0 + prev1;
            
            int curr = max(take, notTake);
            
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;

    }
};
