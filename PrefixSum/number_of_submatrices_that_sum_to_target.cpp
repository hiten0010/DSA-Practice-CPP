class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        
        int count = 0;
        for (int startCol = 0; startCol < cols; startCol++) {
            for (int currCol = startCol; currCol < cols; currCol++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;
                
                for (int row = 0; row < rows; row++) {
                    int currentVal = matrix[row][currCol];
                    if (startCol > 0) {
                        currentVal -= matrix[row][startCol - 1];
                    }
                    sum += currentVal;
                    
                    if (mp.find(sum - target) != mp.end()) {
                        count += mp[sum - target];
                    }
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};
