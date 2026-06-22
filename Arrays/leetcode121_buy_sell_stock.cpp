class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minnumber =INT_MAX;
       int maxprofit =0;
       for(int i =0;i<prices.size();i++){
        if(prices[i]<minnumber){
            minnumber =prices[i];
        }
        else if(prices[i] - minnumber > maxprofit){
            maxprofit =prices[i]-minnumber;
        }
       }
       return maxprofit;
    }
};
