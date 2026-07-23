class Solution {
  public:
    bool searchDirection(vector<vector<char>>& mat, string& word, int x, int y, int dir) {
        int n = mat.size();
        int m = mat[0].size();
        int len = word.length();
        
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        int currX = x + dx[dir];
        int currY = y + dy[dir];
        
        for (int k = 1; k < len; k++) {
            if (currX < 0 || currX >= n || currY < 0 || currY >= m || mat[currX][currY] != word[k]) {
                return false;
            }
            currX += dx[dir];
            currY += dy[dir];
        }
        return true;
    }

    vector<vector<int>> searchWord(vector<vector<char>>& mat, string& word) {
        vector<vector<int>> ans;
        int n = mat.size();
        int m = mat[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    bool found = false;
                    for (int dir = 0; dir < 8; dir++) {
                        if (searchDirection(mat, word, i, j, dir)) {
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        ans.push_back({i, j});
                    }
                }
            }
        }
        return ans;
    }
};
