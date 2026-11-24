class Solution {
public:

  bool solveusingtab(string & s , unordered_set<string> & st){
    int n = s.size();
     vector<bool> dp(n+1 , false);
     dp[n] = true;

     for(int i = n-1 ; i >= 0; i-- ){
        for(int j = i ; j<n ; j++){
            string temp = s.substr(i , j - i + 1);

            if(st.count(temp) && dp[j+1] == true ){
               dp[i] = true;
               break;
            }
        }
     }
     return dp[0];
  }  
    bool wordBreak(string s, vector<string>& wordDict) {
        // Your code goes here
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        return solveusingtab(s, st);
        
    }
};
