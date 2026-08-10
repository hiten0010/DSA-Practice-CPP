class Solution {
  public:
    vector<int> primeRange(int l, int r) {
        // code here

        int limit = sqrt(r);
        vector<bool> mark(limit + 1, true);
        vector<int> basePrimes;
        
        for (int i = 2; i<= limit; i++) {
            if (mark[i]) {
                basePrimes.push_back(i);
                for (int j = i * i; j <= limit; j += i) {
                    mark[j] = false;
                }
            }
        }

        vector<bool> isPrime(r - l + 1, true);
        if (l == 1) {
            isPrime[0] = false; 
        }

        for (int prime : basePrimes) {
            
            int firstMultiple = (l / prime) * prime;
            if (firstMultiple < l) {
                firstMultiple += prime;
            }
            
         
            if (firstMultiple == prime) {
                firstMultiple += prime;
            }

            for (int j = firstMultiple; j <= r; j += prime) {
                isPrime[j - l] = false; 
            }
        }

        vector<int> result;
        for (int i = 0; i <= r - l; i++) {
            if (isPrime[i]) {
                result.push_back(i + l);
            }
        }
        
        return result;
    }
};
