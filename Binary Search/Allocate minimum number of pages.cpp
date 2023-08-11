bool possible(int A[], int n, int M, int mid){
        
        int pagesum = 0 ;
        int studentcount = 1;
        
        for(int i=0; i<n; i++){
            
            if(pagesum + A[i] <= mid){
                pagesum += A[i];
            }
            // if above case is false then max limit comparing to mid is reached so selecting next student
            else{
                studentcount++;
                // A[i] > mid if the next element is itself bigger than mid 
                if(studentcount > M || A[i] > mid){
                    return false;
                }
                // reseting pagesum value for next student
                pagesum = A[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if(M > N) return -1;
        
        int sum =0 ;
        for(int i=0; i<N; i++){
            sum += A[i];
        }
        
        int s = 0;
        int e = sum;
        
        int ans = -1 ;
        
        int mid = (s + e)/2;
        
        while(s<=e){
            
            if(possible(A,N,M,mid)){
                e = mid - 1;
                ans = mid;
            }
            else{
                s = mid + 1;
            }
            
            mid = (s + e)/2;
        }
        
        return ans;
    }