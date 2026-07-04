class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxsize = INT_MIN;
        int right = 1;
        int left =1;
        for(int i =0;i<n;i++){
            if(left==0)left =1;
            if(right==0)right=1;
            right =right*arr[n-i-1];
            left =left*arr[i];
            maxsize =max(maxsize,max(right,left));
        }
        return maxsize;
    }
};
