class Solution {
public:
    int majorityElement(vector<int>& nums) {
     // Optimal Approch
     int count = 0;
     int el = 0;
     
     for(int i = 0 ; i<nums.size(); i++){
        if( count == 0){
            el = nums[i];
            //yaha mistake nhi karni count ko 1 karo
            count = 1;
        }
        else if(nums[i] == el){
            count++;
        }
        else{
            count--;
        }
     }
     return el;

        //Better Approch

        // int n = nums.size();
        // unordered_map<int , int> map;
        // for(int i=0 ; i<n ; i++){
        //     map[nums[i]]++;
        //     if(map[nums[i]] > n/2){
        //         return nums[i];
        //     }
        // }
        // return -1;

        //Brute Force Approch

        // for(int i =0 ; i <n ; i++){
        //     int count = 0;
        //     for(int j =0 ; j < n ; j++){
        //         if(nums[i] == nums[j]){
        //             count++;
        //         }
        //     }
        //     if(count > n/2){
        //         return nums[i];
        //     }
        // }
        // return -1;
    }
};
