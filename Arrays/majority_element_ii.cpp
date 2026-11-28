class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
      
      int n = nums.size();
      int count1 = 0;
      int count2 = 0;
      int el1 = INT_MIN;
      int el2= INT_MIN;
      for(int i =0 ;i<n ; i++){
        if(count1 == 0 && el2 != nums[i]){
            el1 = nums[i];
            count1 = 1;
        }
        else if(count2 == 0 && el1 != nums[i]){
            el2 = nums[i];
            count2 = 1;
        }
        else if(nums[i] == el1){
            count1++;
        }
        else if(nums[i] == el2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
      }
      // Verify 
      vector<int> ans;
      count1 = 0;
      count2 = 0;
      for(int i =0 ; i< n ; i++){
        if(el1 ==nums[i])count1++;
        if(el2 == nums[i])count2++;
      }

      int mini = n/3 +1;

      if(count1 >= mini){
        ans.push_back(el1);
      }
      if(count2 >= mini){
        ans.push_back(el2);
      }
      return ans;

      
       // Better approch 
    //    int n = nums.size();
    //    unordered_map<int , int> mp ;
    //    int mini = n/3 +1;
    //    vector<int> ans;
    //    for(int i =0 ; i< n ; i++){
    //     mp[nums[i]]++;
    //     if(mp[nums[i]] == mini){
    //         ans.push_back(nums[i]);
    //     }

    //     if(ans.size() == 2){
    //         break;
    //     }
    //    }
    //    return ans;


        //Brute force approch
        // int n = nums.size();
        // vector<int> ans;
        // for(int i =0 ; i<n ; i++){
        //     if(ans.size() == 0 || ans[0] != nums[i]){
        //     int sum =0;
        //    for(int j =0 ; j <n ; j++){
        //      if(nums[i] == nums[j]){
        //         sum++;
        //      }
        //    }
        //    if(sum > n/3){
        //     ans.push_back(nums[i]);
        //    }
        //     }

        //     if(ans.size() == 2){
        //         break;
        //     }
        // }
        // return ans;
    }
};
