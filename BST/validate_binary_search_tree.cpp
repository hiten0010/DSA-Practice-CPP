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
bool check(TreeNode * root , long long min , long long max){
    if(root == nullptr){
        return true;
    }
    if( root->val <= min || root->val >= max){
        return false;
    }

    bool left = check(root->left , min , root->val);

    bool right = check(root->right , root->val , max);

    return left && right;
}
    bool isValidBST(TreeNode* root) {
        bool ans = check(root , LLONG_MIN , LLONG_MAX);
        return ans;
    }
};
