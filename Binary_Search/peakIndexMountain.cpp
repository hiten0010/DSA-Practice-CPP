#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int peakelement(vector<int> & nums){
        int n =nums.size();
        int start =0;
        int end =n-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(nums[mid]<nums[mid+1]){
              start=mid+1;
            }
            else{
             end=mid;
            }
        }
        return start;
        
    }
};
int main(){
    vector<int> nums ={10,20,30,80,70,50};
    Solution object;
    int check=object.peakelement(nums);
    cout<<"The peak Element is : "<<check<<endl;
    return 0;
}
