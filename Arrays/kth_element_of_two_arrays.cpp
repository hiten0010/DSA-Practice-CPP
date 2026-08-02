class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
      int point1 = 0;
        int point2 = 0;
        int count = 0;
        
        while (point1 < a.size() && point2 < b.size()) {
            if (a[point1] < b[point2]) {
                count++;
                if (count == k) return a[point1]; 
                point1++;
            } 
            else {
                count++;
                if (count == k) return b[point2];
                point2++;
            }
        }
        
        while (point1 < a.size()) {
            count++;
            if (count == k) return a[point1];
            point1++;
        }
        
        while (point2 < b.size()) {
            count++;
            if (count == k) return b[point2];
            point2++;
        }
        
        return -1;
    }
};
