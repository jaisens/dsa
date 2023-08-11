class Solution {
public:
    bool func(vector<int>& weights, int mid, int D){
        
        //no of days will be 1 because we are incrementing days in else part and summation starts before that
        int days = 1;
        int sum = 0;
        
        for(int i=0; i<weights.size(); i++){
            
            //important to check sum + weights dont forget
            if(sum + weights[i] <= mid) sum += weights[i];
            else{
                sum = weights[i];
                days++;
            }  
        }
        
        //if days found are less than D
        if(days <= D)return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int sum = 0;
        int maxi = INT_MIN;
        
        for(int i=0; i<weights.size(); i++){
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }
        
        int low = maxi; //low will be the maximum element
        int high = sum; //high will be the sum of all elements
        int answer;
        
        //using binary search to find answer
        while(low<=high){
            int mid = (low +  high)/2;
            
            if(func(weights, mid, days)){
                answer = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return answer;
    }
};