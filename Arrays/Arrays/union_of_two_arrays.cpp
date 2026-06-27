class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int> st;
        for(auto & ch : a){
            st.insert(ch);
        }
         for(auto & ch : b){
            st.insert(ch);
        }
        vector<int> ans(st.begin(),st.end());
        return ans;
    }
};
