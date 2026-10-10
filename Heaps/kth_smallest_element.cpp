class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pt;
        int size = arr.size();
        for(int i =0 ; i<k ;i++){
            pt.push(arr[i]);
        }
        
        for(int i = k ; i<size ; i++){
            if(pt.top() > arr[i]){
                pt.pop();
                pt.push(arr[i]);
            }
        }
        return pt.top();
    }
};
