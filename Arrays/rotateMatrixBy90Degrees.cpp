#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void Rotate(vector<vector<int>>& nums){
    int n =nums.size();
    for(int i=0;i<n;i++){
        int m =nums[i].size();
        for(int j =i;j<m;j++){
            swap(nums[i][j],nums[j][i]);
        }
    }
    for(int i =0;i<n;i++){
        reverse(nums[i].begin(),nums[i].end());
    }
    }
};
int main(){
    vector<vector<int>> nums{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution obj;
    obj.Rotate(nums);
    for(int i =0;i<nums.size();i++){
        for(int j =0;j<nums[i].size();j++){
            cout<<nums[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
