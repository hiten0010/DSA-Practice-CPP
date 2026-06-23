#include<iostream>
#include<vector>
void rotate(std::vector<int>& nums){
int start =0;
int end = nums.size()-1;
while(start<end){
    std::swap(nums[start],nums[end]);
    start++;
    end--;
}
}
int main(){
  std::vector<int> nums = {1, 4, 3, 2, 6, 5};
   rotate(nums);
   for(auto & ans : nums){
    std::cout<<ans<<"  ";
   }
    return 0;
}
