#include<iostream>
#include<vector>
void check(std::vector<int> & nums){
    int n = nums.size();
    int z = (1<<n);
    for(int i =0;i<z;i++){
        std::cout<<" [ ";
        for(int j =0;j<n;j++){
            if(i & (1<<j)){
                std::cout<<nums[j]<<" ";
            }   
        }
        std::cout<<"]"<<std::endl;
    }
}
int main(){
    std::vector<int> nums ={1,2,3};
    check(nums);
    return 0;
}
