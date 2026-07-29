class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int candidate = -1;
        int count = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            } else if (arr[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        int verify_count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == candidate) {
                verify_count++;
            }
        }
        
        if (verify_count > n / 2) {
            return candidate;
        }
        
        return -1;
    }
};
