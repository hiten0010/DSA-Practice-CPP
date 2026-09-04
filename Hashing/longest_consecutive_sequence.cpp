class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int num : nums) {
            hashSet.insert(num);
        }
        
        int longestSequence = 0;
        
        for (int num : hashSet) {
            if (!hashSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                
                while (hashSet.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestSequence = max(longestSequence, currentStreak);
            }
        }
        return longestSequence;
    }
};
