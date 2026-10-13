class Node{
    public: 
      int data;
      int row;
      int colindex;
      
      Node(int d , int r , int c){
          this->data = d;
          this->row = r;
          this->colindex = c;
          
      }
  };
  class coustom{
      public:
      bool operator()(Node &a , Node &b){
          return a.data > b.data;
      }
  };
class Solution {
  public:
  
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int n = mat.size();
       
        
        priority_queue<Node , vector<Node> , coustom> pt;
        
        for(int i =0 ; i<n ; i++){
            pt.push(Node(mat[i][0] , i , 0));
        }
        
        vector<int> ans;
        
        while(!pt.empty()){
            Node temp = pt.top();
            pt.pop();
            
            ans.push_back(temp.data);
            
            int row = temp.row;
            int col = temp.colindex;
            
            if(col +1 < mat[row].size()){
                pt.push(Node(mat[row][col + 1], row , col +1));
            }
        }
        return ans;
    }
};
