/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    Node * prev = nullptr;
    Node * head = nullptr;
    
    Node* treeToDLL(Node* root) {
        // code here
        if(root == nullptr){
            return nullptr;
        }
         treeToDLL(root->left);
        
        if(prev == nullptr){
            head = root;
        }
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        
        treeToDLL(root->right);
        
        return head;
    }
};
