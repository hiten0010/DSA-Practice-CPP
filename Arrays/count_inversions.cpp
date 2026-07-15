class Solution {
private:
    int mergeAndCount(vector<int>& arr, int start, int mid, int end) {
        vector<int> temp; 
        int left = start;      
        int right = mid + 1;   
        
        int count = 0;   

        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } 
            else {
                temp.push_back(arr[right]);
                count += (mid - left + 1); 
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= end) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = start; i <= end; i++) {
            arr[i] = temp[i - start];
        }
        return count;
    }
    int mergeSortAndCount(vector<int>& arr, int start, int end) {
        int count = 0;
        
        if (start >= end) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        count += mergeSortAndCount(arr, start, mid);
        count += mergeSortAndCount(arr, mid + 1, end);
        count += mergeAndCount(arr, start, mid, end);

        return count;
    }

public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSortAndCount(arr, 0, n - 1);
    }
};
