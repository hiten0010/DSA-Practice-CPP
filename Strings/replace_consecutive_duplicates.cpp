class Solution {
  public:
    string removeDuplicates(string& s) {
        // code here.
        if (s.length() <= 1) return s;
        
        int j = 0; 
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[j]) {
                j++;             
                s[j] = s[i];     
            }
        }
        return s.substr(0, j + 1);
    }
};
