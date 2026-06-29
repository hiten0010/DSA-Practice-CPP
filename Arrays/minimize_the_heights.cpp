class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n == 1) return 0;
        
        sort(arr.begin(), arr.end());
        int ans = arr[n-1] - arr[0];
        
        int smallest = arr[0] + k;    
        int largest = arr[n-1] - k; 
        
        for(int i = 1; i < n; i++) {
            
            if(arr[i] - k < 0) {
                continue; 
            }

            int current_min = min(smallest, arr[i] - k);
            int current_max = max(largest, arr[i-1] + k);
            
            ans = min(ans, current_max - current_min);
        }
        
        return ans;
    }
};
