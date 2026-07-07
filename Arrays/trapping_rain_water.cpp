class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n <= 2) return 0;
        
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        
        leftMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }
        
        long long total_water = 0;
        for (int i = 0; i < n; i++) {
            int water_level = min(leftMax[i], rightMax[i]);
            
            if (water_level > arr[i]) {
                total_water += (water_level - arr[i]);
            }
        }
        return total_water;
    }
};
