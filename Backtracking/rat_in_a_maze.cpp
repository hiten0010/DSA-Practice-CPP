#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool checking(int x,int y,int n,vector<vector<int>>& nums,vector<vector<bool>> &check){
    if((x>=0 && x<n) && (y>=0 && y<n) && (nums[x][y]==1)&& (check[x][y]==false)){
        return true;
    }
    else {
        return false;
    }
}
void solve(int x,int y,vector<vector<int>>& nums,int n ,vector<vector<bool>> & check,string & path,vector<string> & ans){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    check[x][y]=true;
    int newx;
    int newy;
newx=x+1;
newy =y;
if(checking(newx,newy,n,nums,check)){
    path.push_back('D');
    solve(newx,newy,nums,n,check,path,ans);
    path.pop_back();
}

newx=x;
newy =y-1;
if(checking(newx,newy,n,nums,check)){
    path.push_back('L');
    solve(newx,newy,nums,n,check,path,ans);
    path.pop_back();
}

newx=x;
newy =y+1;
if(checking(newx,newy,n,nums,check)){
    path.push_back('R');
    solve(newx,newy,nums,n,check,path,ans);
    path.pop_back();
}

newx=x-1;
newy =y;
if(checking(newx,newy,n,nums,check)){
    path.push_back('U');
    solve(newx,newy,nums,n,check,path,ans);
    path.pop_back();
    
}
check[x][y]=false;
}
vector<string> findit(vector<vector<int>> & nums, int n){
    vector<string> ans;
    if(nums[0][0]==0)return ans;
    int x =0;
    int y =0;

   
    vector<vector<bool>> check(n,vector<bool>(n,false));
    string path ="";
    solve(x,y,nums,n,check,path,ans);
    return ans;
}
int main(){
    vector<vector<int>> nums{
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = nums.size();
    vector<string> ans =findit(nums,n);
    for(auto & ch : ans){
        cout<<ch<<"    ";
    }
    cout<<endl;
    return 0;
}
