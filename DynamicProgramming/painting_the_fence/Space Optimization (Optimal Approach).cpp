class Solution {
  public:
    int optimizedapproch(int n , int k){
        if(n ==1){
            return k;
        }
        if(n ==2){
            return k*k;
        }
        int prev = k;
        int curr = k*k;
        int ans;
        for(int i =3 ; i<= n ; i++){
            ans = (prev + curr ) * (k - 1);
            prev = curr;
            curr = ans;
        }
        return ans;
    }
    int countWays(int n, int k) {
        // code here
        vector<int> dp(n+1 , -1);
        int ans = optimizedapproch(n, k);
        return ans;
    }
};
