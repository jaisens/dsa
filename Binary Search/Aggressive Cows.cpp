bool possible(vector<int> &stalls,int k,int mid){
        int cowcount = 1;
        // placing the first cow in first index
        int lastposition = stalls[0];
        
        for(int i=0; i<stalls.size(); i++){
            // checking the distance between the cows if greater then placing them
            if(stalls[i] - lastposition >= mid){
                cowcount++;
                if(cowcount == k){
                    return true;
                }
                // updating the position for next cow
                lastposition = stalls[i];
            }
        }
        
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        // very important to sort 
        sort(stalls.begin(),stalls.end());
        
        int maxi = -1;
        
        for(int i=0; i<n; i++){
            maxi = max(maxi , stalls[i]);
        }
        
        int s = 0;
        int e = maxi;
        
        int mid = (s+e)/2;
        int ans = -1;
        
        while(s<=e){

            // mid + 1 because we want to maximise the distance 
            if(possible(stalls,k,mid)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            
            mid = (s+e)/2;
        }
        
        return ans;
    }