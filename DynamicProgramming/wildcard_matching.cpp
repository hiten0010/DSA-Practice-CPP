class Solution {
public:
   int solve(int i , int j, string str, string pat, vector<vector<int>> & dp ){
      if(j < 0 && i < 0){
        return true;
      }
      if(j < 0 && i >= 0){
        return false;
      }
      if(i < 0 && j >= 0){
        for(int a =0 ; a <= j ; a++){
            if(pat[a] != '*'){
                return false;
            }
        }
        return true;
      }
      if(dp[i][j] != -1){
        return dp[i][j];
      }
      if(str[i] == pat[j] || pat[j] == '?'){
           return dp[i][j] = solve(i-1 ,j-1 , str , pat , dp);
      }
      else if(pat[j] == '*'){
          return dp[i][j] = solve(i ,j-1 , str , pat , dp) || solve(i-1 ,j , str , pat , dp);
      }
         return dp[i][j] = false;
   }
    bool wildCard(string str, string pat) {
        int n = str.size();
        int m = pat.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(n -1 ,m -1 , str , pat , dp);
    }
};
