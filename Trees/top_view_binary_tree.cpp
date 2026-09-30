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
    cout<<"Enter thr value of data : ";
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
void printupper(Node *root){
    if(root == nullptr){
        return;
    }
    queue<pair<Node* , int>> qt;

    map<int ,int> mp;

    qt.push({root , 0});
    
    while(!qt.empty()){

        Node * curr = qt.front().first;
        int hd = qt.front().second;
        qt.pop();

        if(mp.find(hd) == mp.end()){
            mp[hd] = curr->data;
        }

        if(curr->left != nullptr){
            qt.push({curr->left , hd -1});
        }
        if(curr->right != nullptr){
            qt.push({curr->right , hd +1});
        }
    }
    for(auto ch : mp){
        cout<<ch.second<<endl;
    }

}
int main(){
    Node * root = Createtree();
    printupper(root);
}
