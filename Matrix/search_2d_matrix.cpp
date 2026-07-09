class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n =arr.size();
        for(int i =0;i<n;i++){
           if(arr[i][0]==target)return true;
           else if(arr[i].back()>=target){
            int m =arr[i].size();
             int start =0;
             int end = m-1;
            while(start <= end){
                int mid = start + (end -start)/2;
                if(arr[i][mid]==target){
                    return true;
                }
                else if(arr[i][mid] < target){
                   start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
           }
        }
        return false;
    }
};
