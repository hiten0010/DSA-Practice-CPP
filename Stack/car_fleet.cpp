class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        vector<pair<int, double>> cars(n);
        
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        
        sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first;
        });
        
        stack<double> st;
        for (int i = 0; i < n; i++) {
            double time = cars[i].second;

            if (!st.empty() && time <= st.top()) {
                continue;
            }
            st.push(time);
        }
        
        return st.size();
    }
};
