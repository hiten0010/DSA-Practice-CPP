/* Binary Tree Node Structure
class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
void inorder(Node * root , vector<int> & ans){
    if(root == nullptr){
        return;
    }
    inorder(root->left , ans);
    
    ans.push_back(root->data);
    
    inorder(root->right , ans);
    
}
void postorder(Node * root , vector<int> & ans , int &index){
    if(root ==nullptr){
        return;
    }
    
    postorder(root->left , ans, index);
    postorder(root->right , ans, index);
    
    root->data = ans[index];
    index++;
    
}
class Solution {
  public:
    void convertToMaxHeap(Node* root) {
        // code here
        vector<int> ans;
        int index =0;
        inorder(root , ans);
        postorder(root , ans , index);
        
    }
};
