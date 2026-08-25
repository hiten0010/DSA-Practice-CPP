class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int count) {
        if (count == word.length()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[count]) return false;

        char temp = board[i][j];
        board[i][j] = '*';
        
        bool found = dfs(board, word, i + 1, j, count + 1) ||
                    dfs(board, word, i - 1, j, count + 1) ||
                     dfs(board, word, i, j + 1, count + 1) ||
                    dfs(board, word, i, j - 1, count + 1);

        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
