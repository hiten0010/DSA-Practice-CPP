class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int count = 0;
        for (auto& pair : freq) {
            if (k == 0) {
                if (pair.second > 1) { 
                    count++;
                }
            } 
            else {
                if (freq.count(pair.first + k)) {
                    count++;
                }
            }
        }
        return count;
    }
};
