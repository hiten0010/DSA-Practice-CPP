class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int first = -1, last = -1;
        
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == x) {
                first = mid;      
                high = mid - 1;   
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        if (first == -1) {
            return {-1, -1};
        }
        
        low = 0; 
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == x) {
                last = mid; 
                low = mid + 1;   
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return {first, last};
    }
};
