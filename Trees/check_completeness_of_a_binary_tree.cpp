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
    int countnodes(TreeNode * root){
       if(root == nullptr) return 0;
       return 1 + countnodes(root->left) + countnodes(root->right);
    }
    bool checkCBT(TreeNode * root , int index , int count){
       if(root == nullptr){
        return true;
       }

       if(index >= count){
        return false;
       }

       bool left = checkCBT(root->left , 2 * index + 1 , count);
       bool right = checkCBT(root->right , 2 * index + 2 , count);

       return left && right;
    }
    bool isCompleteTree(TreeNode* root) {
        int count = countnodes(root);
        return checkCBT(root , 0 , count);
    }
};
