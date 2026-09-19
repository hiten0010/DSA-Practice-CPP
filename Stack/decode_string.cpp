class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currStr = "";
        int currNum = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } 
            else if (c == '[') {
                numStack.push(currNum);
                strStack.push(currStr);
                currStr = "";
                currNum = 0;
            } 
            else if (c == ']') {
               
                int k = numStack.top();
                numStack.pop();
                
                string prevStr = strStack.top();
                strStack.pop();
                
                string repeatedStr = "";
                while (k--) {
                    repeatedStr += currStr;
                }
                
               currStr = prevStr + repeatedStr;
            } 
            else {
              currStr += c;
            }
        }
        return currStr;
    }
};
