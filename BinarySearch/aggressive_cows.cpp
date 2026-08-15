class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int minDist) {
                int cowsCount = 1;
                int lastPos = arr[0];

                for (int i = 1; i < arr.size(); i++) {
                    if (arr[i] - lastPos >= minDist) {
                        cowsCount++;
                        if (cowsCount == k) return true;
                        lastPos = arr[i];
                    }
                }
                return false;
            }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
                sort(arr.begin(), arr.end());
                int low = 1;
                int high = arr.back() - arr[0];
                int ans = -1;

                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    
                    if (isPossible(arr, k, mid)) {
                        ans = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return ans;
            }
        };
