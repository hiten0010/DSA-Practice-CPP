class Solution{
    public: 
    int getLCS(int i , int j, string a , string b , vector<vector<int>> &dp){
        if(i ==0 || j== 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(a[i -1 ] == b[j -1 ]){
            dp[i][j] =  1 + getLCS(i-1 , j-1 , a , b, dp);
        }
        else{
            dp[i][j] = max(getLCS(i -1, j , a , b , dp) , getLCS(i ,j-1 , a, b, dp));
        }
        return dp[i][j];
    }
    string shortestCommonSupersequence(string str1, string str2){
        int n = str1.size();
        int m = str2.size();
        
        vector<vector<int>> dp(n+1 ,vector<int>(m+1 , -1));

        getLCS(n ,m , str1 , str2 , dp);

        int i = n;
        int j = m;
        string ans ="";

        while(i > 0 && j > 0){
            if(str1[i -1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else{
                if( getLCS(i -1, j , str1 , str2 , dp) >  getLCS(i ,j-1 , str1 , str2 , dp)){
                    ans += str1[i -1];
                    i--;
                }
                else{
                    ans += str2[j-1];
                    j--;
                }
            }
        }
        while(i > 0){
            ans += str1[i -1];
            i--;
        }
        while( j >0){
            ans += str2[j -1];
            j--;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
