class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pt;

        for(auto ch : piles){
            pt.push(ch);
        }

        while(k--){
            int temp = pt.top();
            pt.pop();

            int remain = temp - temp / 2 ;

            pt.push(remain);
        }
        int sum = 0;

        while(!pt.empty()){
         sum += pt.top();
         pt.pop();
        }
        return sum;
    }
};
