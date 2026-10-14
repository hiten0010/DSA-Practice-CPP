class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>> pt;

        if(a > 0) pt.push({a , 'a'});
        if(b > 0) pt.push({b , 'b'});
        if(c > 0) pt.push({c , 'c'});
        
        string ans ="";
        while(!pt.empty()){
            pair<int , char> curr = pt.top();
            pt.pop();
            int n = ans.size();
            if(n >= 2 && ans[n-1] == curr.second && ans[n-2] == curr.second){
                if(pt.empty()){
                    break;
                }

                pair<int , char> next = pt.top();
                pt.pop();

                ans += next.second;
                next.first--;

                if(next.first > 0){
                    pt.push(next);
                }
                pt.push(curr);
            }
            else{
                ans += curr.second;
                curr.first--;

                if(curr.first > 0){
                    pt.push(curr);
                }   
            }
        }
        return ans;
    }
};
