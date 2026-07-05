class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        // code here
        int n = arr.size();
        int length =0;
        unordered_set<int> st;
       for(int i =0;i<n;i++){
           st.insert(arr[i]);
       }
       for(int i =0;i<n;i++){
           int current_number =arr[i];
           if(st.find(current_number -1) == st.end()){
               int first_number = current_number;
               int count =1;
               while(st.find(first_number +1) != st.end()){
                   first_number = first_number +1;
                   count++;
               }
               length = max(length , count);
           }
       }
       return length;
    }
};
