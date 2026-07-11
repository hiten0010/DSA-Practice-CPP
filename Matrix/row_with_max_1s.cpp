class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
     int n = arr.size();
        int m = arr[0].size();
        int row = 0;
        int col = m - 1; 
        int ans_row = -1;
 
        while (row < n && col >= 0) {
            
            if (arr[row][col] == 1) {
                ans_row = row;
                col--;         
            } 
            else {
                row++;  
            }
        }
        return ans_row;
    }
};
