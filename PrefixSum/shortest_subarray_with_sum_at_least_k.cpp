class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        deque<int> dq;
        int min_len = INT_MAX;

        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && pref[i] - pref[dq.front()] >= k) {
                min_len = min(min_len, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && pref[i] <= pref[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return min_len == INT_MAX ? -1 : min_len;
    }
};
