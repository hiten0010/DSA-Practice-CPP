#include<iostream>
#include<vector>
#include <climits>
std::pair<int,int> findmaxmin(const std::vector<int> & nums){
int max = INT_MIN;
int min=INT_MAX;
for(int i=0;i<nums.size();i++){
    if(nums[i]>max){
        max=nums[i];
    }
    if(nums[i]<min){
        min=nums[i];
    }
}
return {max,min};
}
int main(){
    std::vector<int> nums {3, 5, 4, 1, 9};
    std::pair<int, int> ans = findmaxmin(nums);
    std::cout << "Maximum number is : " << ans.first << "\n";
    std::cout << "Minimum number is : " << ans.second << "\n";
}
