/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Nodecheck{
    public :
    int size;
    int mini;
    int maxi;
    bool valid;
    Nodecheck(){} 
    
    Nodecheck(int s , int mi , int mx , bool isvalid): size(s) , mini(mi) , maxi(mx) ,valid(isvalid) {}
};
class Solution {
  public:
    Nodecheck solve(Node * root , int  &ans){
        if(root == nullptr){
            return{0 , INT_MAX , INT_MIN , true};
        }
        Nodecheck left = solve(root->left , ans);
        Nodecheck right = solve(root->right , ans);
        
        Nodecheck curr;
        curr.size = left.size + right.size + 1;
        curr.mini = min(root->data , left.mini);
        curr.maxi = max(root->data , right.maxi);
        
        if(left.valid == true && right.valid == true && (root->data > left.maxi && root->data < right.mini)){
            curr.valid = true;
        }
        else{
            curr.valid = false;
        }
        if(curr.valid == true){
            ans = max(ans , curr.size);
        }
        return curr;
    }
    int largestBst(Node *root) {
        // code here
        int ans =0;
        solve(root ,ans);
        return ans;
    }
};
