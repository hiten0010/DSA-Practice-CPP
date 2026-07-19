#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void solve(string s, string &temp, vector<bool> &visited, vector<string> &ans) {

        if (temp.length() == s.length()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            
            if (visited[i]) continue;


            if (i > 0 && s[i] == s[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;
            temp.push_back(s[i]);
            
            solve(s, temp, visited, ans);

            visited[i] = false;
            temp.pop_back();
        }
    }

public:
    vector<string> findPermutation(string s) {
        vector<string> ans;
        string temp = "";
        
        vector<bool> visited(s.length(), false);

        sort(s.begin(), s.end());

        solve(s, temp, visited, ans);
        
        return ans;
    }
};
