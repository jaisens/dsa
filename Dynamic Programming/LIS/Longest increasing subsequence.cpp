int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        // single element count 1
        vector<int> dp(n,1);

        // because a single element is also included
        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],1 + dp[j]);
                    ans = max(ans,dp[i]);
                }
            }
        }

        return ans;
}
// TC = O(n^2) SC = O(n)


// try the nlogn solution