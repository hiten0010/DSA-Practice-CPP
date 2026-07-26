class Solution {
  public:
    bool canRearrange(string& s) {
        // code here
        vector<int> check(26,0);
        int max_freq =0;
        for(char ch : s){
            check[ch - 'a']++;
            if(check[ch-'a'] > max_freq){
                max_freq = check[ch-'a'];
            }
        }
        int n = s.length();
        if(max_freq > (n+1)/2){
            return false;
        }
        return true;
    }
};
