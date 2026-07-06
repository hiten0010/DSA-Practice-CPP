class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int current_sum = arr[i] + arr[left] + arr[right];
                
                if (current_sum == target) {
                    return true;
                } else if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return false;
    }
};
