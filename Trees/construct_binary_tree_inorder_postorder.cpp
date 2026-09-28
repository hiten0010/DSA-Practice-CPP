/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * build(vector<int>& inorder, vector<int>& postorder , int & index , int left , int right){
     if(left > right){
        return nullptr;
     }

     int val = postorder[index];
     index--;
     
     TreeNode * root = new TreeNode(val);

     int pos = left;

     while(  inorder[pos] != val ){
        pos++;
     }

     root->right =build( inorder , postorder , index , pos +1  , right );
     root->left =build( inorder , postorder , index , left  , pos-1 );

     return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() -1 ;

        TreeNode * root = build( inorder , postorder , index , 0 , inorder.size() -1 );
        return root;
    }
};
