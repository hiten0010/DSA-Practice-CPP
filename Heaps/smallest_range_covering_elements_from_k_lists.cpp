class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        class Node{
            public:
            int data;
            int row;
            int col;

            Node(int d , int r , int c){
                this->data = d;
                this->row =r;
                this->col = c;
            }
        };
        class compare{
            public:
            bool operator()(Node &a , Node &b){
                return a.data > b.data;
            }
        };
        priority_queue< Node , vector<Node> , compare> pt;
        int maxvalue = INT_MIN;

        for(int i =0 ; i < nums.size(); i++){
            pt.push(Node(nums[i][0] , i , 0));
            maxvalue = max(maxvalue , nums[i][0]);
        }
        int rangestart = 0;
        int rangeend = INT_MAX;

        while(true){
            Node temp = pt.top();
            pt.pop();

            int minvalue = temp.data;

            if(maxvalue - minvalue < rangeend - rangestart){
                rangeend = maxvalue;
                rangestart = minvalue;
            }
            int col = temp.col;
            int row = temp.row;

            if(col + 1 == nums[row].size()){
                break;
            }
            int nextval = nums[row][col +1];
            pt.push(Node(nextval , row , col+1));
            maxvalue = max(maxvalue , nextval);
        }
        return {rangestart , rangeend};
    }
};
