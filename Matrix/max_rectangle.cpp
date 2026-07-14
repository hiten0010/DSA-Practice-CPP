class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int m = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i <= m; i++) {
            while (!st.empty() && (i == m || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                
                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

public:
    int maxArea(vector<vector<int>>& mat) {
        if (mat.empty()) return 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> heights(m, 0);
        int maxA = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            maxA = max(maxA, largestRectangleArea(heights));
        }
        
        return maxA;
    }
};
