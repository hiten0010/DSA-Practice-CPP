class Solution {
public:

    int solveusingtabSO(int p , int q ,string& text1, string &text2){
        int n = text1.length();
        int m = text2.length();
        if(m > n) {
            swap(text1, text2);
            swap(n, m);
        }
        vector<int> curr(m+1 , 0);
        vector<int> prev(m+1 , 0);
        for(int i = n-1; i >= 0 ; i--){
            for(int j  = m-1 ; j>=0 ; j--){
                
                if(text1[i] == text2[j]){
                    curr[j] = 1 + prev[j+1];
                }
                else{
                    curr[j] = max(prev[j] , curr[j+1]);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // vector<vector<int>> dp(n+1 ,vector<int>(m+1 , -1));
        return solveusingtabSO(0 , 0 ,text1 , text2 );
        
    }
};
