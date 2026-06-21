class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n =nums.size();
        int start =-1;
        for(int i =n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
            start =i;
              break;}
        } 
        
        if(start == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>start;i--){
            if(nums[i]>nums[start]){
                swap(nums[i],nums[start]);
                break;
            }
        }
        reverse(nums.begin()+start+1,nums.end());
    }
};
