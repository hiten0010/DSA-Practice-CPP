class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size());
        
        for(int i = arr.size()-1 ;i>=0 ;i--){
            int val = arr[i];
            
            while(st.top() >= val){
                st.pop();
            }
            ans[i] = st.top();
            
            st.push(val);
        }
        return ans;
    }
};
