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
    bool solve(TreeNode * root , int k, unordered_set<int> & st ){
        if(root == nullptr){
            return false;
        }
        int diff = k - root->val;

        if(st.find(diff) != st.end()){
            return true;
        }
        st.insert(root->val);

        bool left = solve(root->left , k , st);
        bool right = solve(root->right , k , st);

        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;

        return solve(root , k , st);
    }
};
