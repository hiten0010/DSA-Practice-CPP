class Solution{   
public: 

    int usingtab(string s){
        string t = s;
        int n = s.length();
        reverse(t.begin() , t.end());
        vector<vector<int>> dp(n +1 , vector<int>(n +1,0));
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j=n-1 ; j >= 0 ; j--){
                if(t[i] == s[j]){
                  dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }

    int minInsertion(string s) {
        int n = s.length();
       int ans = usingtab(s);
       return n - ans;
  }
};
