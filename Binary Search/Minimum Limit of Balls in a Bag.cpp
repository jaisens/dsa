class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int left = 1;
        int right = 1e9;
        
        while(left<right){
            int mid = left + (right-left)/2;
            int count = 0;
            
            //assume mid is the minimum penalty for each element count the number of operations will be required to 
            //break that value to mid value 
            for(auto it : nums){
                count += (it - 1)/mid;
            }
            
            if(count > maxOperations){
                left = mid + 1;
            }
            else{
                //not mid - 1 because then we will need to store the answer or else it will be lost
                right = mid;
            }
        }
        
        return left;
    }
};