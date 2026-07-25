class Solution {
  public:
    int findSubString(string& str) {
        // code here
        vector<bool> visited(256, false);
        int distinct_count = 0;
        
        for (char ch : str) {
            if (!visited[ch]) {
                visited[ch] = true;
                distinct_count++;
            }
        }
        
        vector<int> char_count(256, 0);
        int start = 0, min_len = INT_MAX;
        int count = 0;
        
        for (int end = 0; end < str.length(); end++) {
            char_count[str[end]]++;
            
            if (char_count[str[end]] == 1) {
                count++;
            }
            
            if (count == distinct_count) {
                while (char_count[str[start]] > 1) {
                    char_count[str[start]]--;
                    start++;
                }
                
                min_len = min(min_len, end - start + 1);
            }
        }
        
        return min_len;
    }
};
