class Solution {
public:
    vector<int> nextsmaller(vector<int>  & v){
        stack<int> st;
        st.push(-1);
        vector<int> ans(v.size());

        for(int i = v.size() -1 ; i >= 0; i--){
            int val = v[i];
            while(st.top() != -1 && v[st.top()] >= val){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevsmaller(vector<int>  & v){
        stack<int> st;
        st.push(-1);
        vector<int> ans(v.size());

        for(int i = 0; i < v.size(); i++){
            int val = v[i];
            while(st.top() != -1 && v[st.top()] >= val){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
         
        vector<int> next = nextsmaller(heights);

        vector<int> prev = prevsmaller(heights);
        
        int finalans = INT_MIN;

        for(int i =0 ; i<heights.size() ; i++){
            int length = heights[i];

            if(next[i] == -1){
                next[i] = heights.size();
            }

            int weidth = next[i] - prev[i] -1;

            int ans = length * weidth;

            finalans = max(finalans , ans);
        }
        return finalans;
    }
};
