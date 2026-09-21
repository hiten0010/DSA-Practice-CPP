#include<iostream>
#include<queue>
#include<string>
using namespace std;
string findNonrepeating(string & s){
     string ans ="";
     queue<char> q;
     int frequency[26] ={0};

     for(int i =0 ; i<s.size() ; i++){
        char ch = s[i];

        frequency[ch -'a']++;

        q.push(ch);

        while(!q.empty() && frequency[q.front() -'a'] > 1){
            q.pop();
        }

       if(q.empty()){
         ans += '#'; 
       } 
       else{
        ans += q.front();
       }
     }
      return ans;
}
int main(){
    string s = {"aabcbcd"};

    cout<< findNonrepeating(s)<<endl;
    return 0;
}
