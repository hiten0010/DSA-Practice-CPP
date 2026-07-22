class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int n = s.length();
        vector<int> check(n,0);
        int len =0;
        int i =1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                check[i]=len;
                i++;
            }
            else{
                if(len != 0){
                    len =check[len-1];
                }
                else{
                    check[i]=len;
                    i++;
                }
            }
        }
        return check[n-1];
    }
};
