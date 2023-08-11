class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long count = 0;
    void merge(long long arr[],long long low,long long mid,long long high){
        
        vector<long long> temp;
        
        long long left = low;
        long long right = mid + 1;
        
        
        while(left <= mid && right <=high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                // see the notes
                temp.push_back(arr[right]);
                count += mid - left + 1;
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=high){
            temp.push_back(arr[right]);
            
            right++;
        }
        
        
        for(long long i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
    }
    void mergesort(long long arr[],long long low,long long high){
        if(low >= high) return;
        
        long long mid = (high + low)/2;
        
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        mergesort(arr,0,n-1);
        return count;
    }

};