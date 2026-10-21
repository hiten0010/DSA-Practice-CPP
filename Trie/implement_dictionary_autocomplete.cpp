#include<iostream>
#include<vector>
#include<string>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode * arr[26];
    bool isTerminal;

    TrieNode(char c){

    this->data = c;
    this->isTerminal = false;
    for(int i =0 ; i<26 ; i++){
        arr[i] = nullptr;
    }
    }
};
void insertion(TrieNode * root , string s){
    if(s.length() == 0){
        root->isTerminal = true;
        return;
    }
    char ch = s[0];
    int index = ch - 'a';

    TrieNode * child;
    if(root->arr[index] != nullptr){
        child = root->arr[index];
    }
    else{
        child = new TrieNode(ch);
        root->arr[index] = child;
    }

    insertion(child , s.substr(1));
}
void printword(TrieNode * root , string s , int length){
    if(root->isTerminal == true){
        cout<<s.substr(length)<<"  ";

    }  
    for(int i =0 ; i<26 ; i++){
        if(root->arr[i] != nullptr){
            char c = i + 'a';
            printword(root->arr[i] , s + c ,length);
        }
    }
}
void checkprefix(TrieNode * root , string prefix){
    TrieNode * curr = root;
    int length = prefix.length();
    for(int i =0 ; i<prefix.length() ; i++){
       int index = prefix[i] - 'a';

       if(curr->arr[index] == nullptr){
        cout<<"Not Found "<<endl;
        return;
       }

       curr = curr->arr[index];
    }

    printword(curr , prefix , length);
}
int main(){
    vector<string> words = {"code", "coder", "coding", "college", "cat", "car"};
    string word = "code";
    TrieNode * root = new TrieNode('\0');
    for(auto ch : words){
        insertion(root , ch);
    }
    string ans ="";
    for(int i =0 ; i<word.length() ; i++){
        ans += word[i];
        checkprefix(root , ans);
        cout<<endl;
    }
}
