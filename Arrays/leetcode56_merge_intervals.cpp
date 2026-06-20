class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans ;
        for(auto& nums : intervals){
         if(!ans.empty() && ans.back()[1] >= nums[0]){
              ans.back()[1] = max(ans.back()[1],nums[1]);
         }
         else{
            ans.push_back(nums);
         }
        }
        return ans;
    }
};
