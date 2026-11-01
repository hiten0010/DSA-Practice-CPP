class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<int> curr(W+1 , 0);
        
        for(int i =0 ; i < n ; i++){
            for(int j = W ; j >= 0 ; j--){
                int pick = 0;
                if(j >= wt[i]){
                    pick = val[i] + curr[j - wt[i]];
                }
                int notpick = curr[j];
                
                curr[j] = max(pick ,notpick);
            }
            
        }
        return curr[W];
    }
};
