class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int> m;
        int maxnum = INT_MIN;
        for(auto ch : s){
            m[ch]++;
            maxnum = max(maxnum , m[ch]);
        }
        
        if(maxnum > (s.size() + 1) /2  ){
            return "";
        }
        priority_queue<pair<int , char>> pt;

        for(auto ch : m){
            pt.push({ch.second , ch.first});
        }
        string ans ="";
        pair<int , char> prev{0 ,'#'};
        while(!pt.empty()){
            pair<int , char> temp = pt.top();
            pt.pop();
            
            ans += temp.second;
            temp.first--;

            if(prev.first > 0){
                pt.push(prev);
            }
            prev = temp;
        }
        return ans;
    }
};
