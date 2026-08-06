class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;
        int prevCount = 0;
        
        for (const string& row : bank) {
            int currCount = count(row.begin(), row.end(), '1');
            
            if (currCount > 0) {
                totalBeams += prevCount * currCount;
                prevCount = currCount;
            }
        }
        return totalBeams;
    }
};
