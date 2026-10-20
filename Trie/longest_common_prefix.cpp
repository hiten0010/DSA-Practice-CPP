class Solution {
public:
    class TrieNode{
        public :
        char data;
        TrieNode * child[26];
        bool isTerminal;

        TrieNode(char c){
            this->data = c;
            for(int i =0 ; i<26 ; i++){
                child[i] = nullptr;
            }
            isTerminal = false;
        }
    };
    void insertion(TrieNode * root , string s){
        if(s.length() == 0){
            root->isTerminal = true;
            return;
        }
        char ch = s[0];
        int i = ch - 'a';
        TrieNode * temp;

        if(root->child[i] != nullptr){
            temp = root->child[i];
        }
        else{
            temp = new TrieNode(ch);
            root->child[i] = temp;
        }
        insertion(temp , s.substr(1));
    }
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('\0');
        for(auto ch :strs){
            insertion(root , ch);
        }
        TrieNode * curr = root;
        string ans = "";
        while(true){
        int count = 0;
        int index = -1;
        for(int i =0 ; i<26 ; i ++){
            if(curr->child[i] != nullptr){
                count++;
                index = i;
            }
        }
        if(count != 1 || curr->isTerminal == true){
            break;
        }
        ans += (index +'a');
        curr = curr->child[index];

        }
        return ans;
    }
};
