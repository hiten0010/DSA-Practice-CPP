class Solution {
  public:
    int primeProduct(int L, int R) {
        // code here
            long long l = L;
            long long r = R;
            long long MOD = 1000000007;
            long long limit = sqrt(R);
            vector<bool> mark(limit + 1, true);
            vector<long long> basePrimes;

            for (long long i = 2; i <= limit; i++) {
                if (mark[i]) {
                    basePrimes.push_back(i);
            for (long long j = i * i; j <= limit; j += i) {
                    mark[j] = false;
                        }
                    }
                }

                vector<bool> isPrime(r - l + 1, true);
                if (l == 1) isPrime[0] = false;

                for (long long prime : basePrimes) {
                    long long firstMultiple = (l / prime) * prime;
                    if (firstMultiple < l) firstMultiple += prime;
                    if (firstMultiple == prime) firstMultiple += prime;

                    for (long long j = firstMultiple; j <= r; j += prime) {
                        isPrime[j - l] = false;
                    }
                }

                long long product = 1;
                bool hasPrime = false; 

                for (long long i = 0; i <= r - l; i++) {
                    if (isPrime[i]) {
                        product = (product * (i + l)) % MOD;
                        hasPrime = true;
                    }
                }
                return hasPrime ? product : 1;
            }
        };
