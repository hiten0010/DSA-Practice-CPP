#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> firstnegative(vector<int> arr , int k){
    int size = arr.size();
    deque<int> dq;
    vector<int> ans;
    for(int i =0; i<size ;i++){
     if(arr[i] < 0){
        dq.push_back(i);
     }

     if(!dq.empty() && dq.front()== i-k){
        dq.pop_front();
     }
     
     if(i >= k-1){
        if(!dq.empty()){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
     }
    
    }
    return ans;
}
int main(){
    vector<int> arr ={12,-1,-7,8,-15,30,16,18};
    int k =3;
    vector<int> ans = firstnegative(arr, k);
    for( auto ch : ans){
        cout<<ch<<"   ";
    }
    cout<<endl;
}
