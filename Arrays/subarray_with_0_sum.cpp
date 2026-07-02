class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
   
        unordered_set<int> seen_sums;
        int running_sum = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            running_sum += arr[i];
            
            if (running_sum == 0 || seen_sums.find(running_sum) != seen_sums.end()) {
                return true;
            }
            
            seen_sums.insert(running_sum);
        }
        
        return false;
    }
};
