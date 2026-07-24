class Solution {
  public:
    int minimumNumberOfSwaps(string& s) {
        // code here
        int swaps = 0;
        int open = 0, close = 0;
        
        for (char ch : s) {
            if (ch == ']') {
                close++;
            } else {
                if (close > open) {
                    swaps += (close - open);
                }
                open++;
            }
        }
        return swaps;
    }
};
