class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        int n = arr.size();
        int count =0;
        sort(arr.begin(), arr.end());
        for(int i =0;i<n-2;i++){
            int start = i+1;
            int end = n-1;
            while(start<end){
            if(arr[i]+ arr[start]+arr[end]>=sum){
               end--;
            }
            else{
                 count += (end - start);
                start++;
            }
            }
        }
        return count;
    }
};
