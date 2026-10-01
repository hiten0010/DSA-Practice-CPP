#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
    public :
    int data;
    Node * left ;
    Node *right;

    Node(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;

    }
};
Node * Createtree(){
    int data;
    cout<<"Enter the value of data : ";
    cin>>data;
    cout<<endl;
    if(data == -1){
        return nullptr;
    }

    Node * root = new Node(data);

    root->left = Createtree();
    root->right = Createtree();
    
    return root;
}
bool checkNode(Node * temp){
    if(temp->left == nullptr && temp->right == nullptr){
         return true;
    }
    return false;
}
void lefttraverse(Node * root, vector<int> &ans){
    Node * curr = root->left;
    while(curr!= nullptr){
      if(checkNode(curr)== false){
        ans.push_back(curr->data);
      }

      if(curr->left != nullptr){
        curr = curr->left;
      }
      else{
        curr=curr->right;
      }
    }
}
void rootnodes(Node *root ,vector<int> &ans){
   if(checkNode(root)){
    ans.push_back(root->data);
    return;
   }
   if(root->left != nullptr){
    rootnodes(root->left , ans);
   }
   if(root->right != nullptr){
    rootnodes(root->right , ans);
   }
}
void righttraverse(Node * root, vector<int> &ans){
    vector<int>temp;
    Node * curr = root->right;
    while(curr!= nullptr){
      if(checkNode(curr) == false){
        temp.push_back(curr->data);
      }

      if(curr->right != nullptr){
        curr = curr->right;
      }
      else{
        curr=curr->left;
      }
    }
    for(int i = temp.size() -1 ; i >= 0;i--){
        ans.push_back(temp[i]);
    }
}
int main(){
    Node * root = Createtree();
    vector<int> ans;
    if(checkNode(root)== false){
        ans.push_back(root->data);
    }
    lefttraverse(root , ans);
    rootnodes(root , ans);
    righttraverse(root, ans);

    for(auto ch : ans){
        cout<<ch<<"   ";
    }
    cout<<endl;
    return 0;
}
