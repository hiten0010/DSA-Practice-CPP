class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<bool> check(n,true);
        check[0]=check[1]=false;
        for(int i =2;i*i<n;i++){
            if(check[i]){
                for(int j =(long long)i *i ;j<n;j += i){
                    check[j]=false;
                }
            }
        }
        int count =0;
        for(int i =2;i<n;i++){
            if(check[i])count++;
        }
        return count;
    }
};
