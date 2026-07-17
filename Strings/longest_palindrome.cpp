class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int n = s.size();
        if(n==0){
            return "";
        }
        int maxi = INT_MIN;
        int start =-1;
        int length =0;
            for(int i =0;i<n;i++){
            int right =i;
            int left =i;
            while(left >=0 && s[right]==s[left] && right <n){
                right++;
                left--;
                }
            int length2 = right -left -1;
             if(length2>maxi){
                maxi = length2;
                start = left +1;
                length =length2;
            }

            right =i+1;
            left =i;
            while(left >=0 && s[right]==s[left] && right <n){
                right++;
                left--;
            }
            int length1 = right -left -1;
             if(length1>maxi){
                maxi = length1;
                start = left +1;
                length =length1;
            }
            }
        return s.substr(start,length);
    }
};
