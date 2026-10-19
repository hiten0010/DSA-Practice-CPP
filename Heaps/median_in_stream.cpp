class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double> ans;
        priority_queue<int> leftside;
        priority_queue<int , vector<int> , greater<int>> rightside;
        for(auto ch : arr){
            
             if(leftside.empty() || ch <= leftside.top()){
                 leftside.push(ch);
             }
             else{
                 rightside.push(ch);
             }
             
             if(leftside.size() > rightside.size() + 1){
                 rightside.push(leftside.top());
                 leftside.pop();
             }
             else if(rightside.size() > leftside.size()){
                 leftside.push(rightside.top());
                 rightside.pop();
             }
            
            if(leftside.size() > rightside.size()){
                ans.push_back( leftside.top() );
            }
            else{
                ans .push_back( (leftside.top() + rightside.top())/2.0);
            }
        }
        return ans;
    }
};
