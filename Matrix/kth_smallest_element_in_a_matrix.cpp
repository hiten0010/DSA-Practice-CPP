class Solution {
  public:
    int countLessOrEqual(vector<vector<int>>& mat, int mid, int n) {
        int count = 0;
        int row = 0;
        int col = n - 1;
        
        while (row < n && col >= 0) {
            if (mat[row][col] <= mid) {
                count = count + (col + 1);
                row++;
            } else {
                col--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n - 1][n - 1];
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countLessOrEqual(mat, mid, n);
            
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
    }
};

