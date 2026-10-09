// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    // Function to sort an array using Heap Sort.
    void heapify(vector<int>& arr ,int n ,int index){
        while(true){
        int largest = index;
       
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }
        
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }
        
        if(largest == index){
            break;
        }
        swap(arr[largest] , arr[index]);
        
        index = largest;
        }
    }
    void heapSort(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        for(int i = n/2 -1 ;i>= 0 ;i--){
            heapify(arr ,n,  i);
        }
        
        for(int i = n -1 ; i > 0 ;i--){
            
        swap(arr[0], arr[i]);
        
        heapify(arr ,i , 0);
    }
    }
};
