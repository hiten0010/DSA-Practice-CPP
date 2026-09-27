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
   void solve(TreeNode * root , int targetSum , vector<int> &ans , vector<vector<int>> &finalans){
      if(root == nullptr){
        return ;
      }
      ans.push_back(root->val);
      if(root->left == nullptr && root->right == nullptr){
        if(targetSum == root->val){
         finalans.push_back(ans);
         
        }
        ans.pop_back();
        return;
      }
      targetSum -= root->val;
      
      solve(root->left , targetSum, ans , finalans );

      solve(root->right , targetSum, ans , finalans );

      ans.pop_back();
   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> finalans;
        
        vector<int> ans;
        
        solve(root , targetSum , ans ,finalans);
        return finalans;
    }
};
