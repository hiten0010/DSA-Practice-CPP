class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int current_sum = 0;
        int count = 0;
        for (int num : nums) {
            current_sum += num;
            int remove = current_sum - k;

            if (mpp.find(remove) != mpp.end()) {
                count += mpp[remove];
            }

            mpp[current_sum]++;
        }
        return count;
    }
};
