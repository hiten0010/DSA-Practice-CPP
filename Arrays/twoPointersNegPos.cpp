#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void arrange(vector<int> & nums){
        int n = nums.size();
        int left =0;
        int right = n -1;
        while(left<right){
            
            if(nums[left]<0){
                left++;
            }
            else if(nums[right]>0){
                right--;
            }
            else{
                swap(nums[left],nums[right]);
            }
        }
    }
};
int main(){
    vector<int> nums ={-2,5,4,-5,9,-8,3};
    Solution obj;
    obj.arrange(nums);
    for(int i =0;i<nums.size();i++){
        cout<<nums[i]<<"   ";
    }
    return 0;
}
