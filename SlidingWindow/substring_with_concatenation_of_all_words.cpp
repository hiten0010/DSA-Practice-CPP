class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int n = s.length();

        unordered_map<string, int> wordCount;
        for (string word : words) {
            wordCount[word]++;
        }
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            int count = 0;
            unordered_map<string, int> window;

        while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;

            if (wordCount.find(word) != wordCount.end()) {
                    window[word]++;
                    count++;

            while (window[word] > wordCount[word]) {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    count--;
                    left += wordLen;
                    }

                if (count == numWords) {
                    ans.push_back(left);
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return ans;
    }
};
