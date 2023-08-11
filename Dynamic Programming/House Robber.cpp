class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int dp[n+1];

        dp[0] = 0; //when none of the houses are robbed
        dp[1] = nums[0]; //maximum of when 1st house is robbed

        for(int i=2; i<=nums.size(); i++){
            dp[i] = max(nums[i-1]+dp[i-2],dp[i-1]);     //when house is selected 
        }

        return dp[n];
    }
};

