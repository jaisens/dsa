class Solution {
public:
    //using space optimization method
    int solve(vector<int>& nums,int n){

        int prev2=0;
        int prev1=nums[0];

        for(int i=1; i<n; i++){
            int inc = nums[i];
            if(i>1) inc += prev2;
            int exc = prev1;
            int ans = max(inc,exc);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> first,second;

        //removing first element or the last element as the houses are in circle and the first and last 
        //house are adjacrent to each other
        for(int i=0; i<n; i++){
            if(i != n-1)
                first.push_back(nums[i]);
            
            if(i != 0)
                second.push_back(nums[i]);
        }

        return max(solve(first,n-1),solve(second,n-1));

    }
};