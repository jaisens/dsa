class Solution {
public:
    int solve(int index,int diff,vector<int>& nums){

        if(index < 0)
            return 0;

        int ans = 0;
        for(int i=index-1; i>=0; i--){
            if(nums[index]-nums[i] == diff){
                ans = max(ans,1+solve(i,diff,nums));
            }
        }
        return ans;
    }
    int solvemem(int index,int diff,vector<int>& nums,vector<vector<int>>& dp){

        if(index < 0)
            return 0;

        if(dp[index][diff] != -1) return dp[index][diff];
        
        int ans = 0;
        for(int i=index-1; i>=0; i--){
            if(nums[index]-nums[i] + 500 == diff){
                ans = max(ans,1+solvemem(i,diff,nums,dp));
            }
        }
        return dp[index][diff] = ans;
    }
    int solvetab(vector<int>& nums){
        vector<vector<int>> dp(nums.size(),vector<int>(1001,0));

        int res=2,diff;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                diff = nums[j] - nums[i] + 500;
                dp[j][diff] = max(2,dp[i][diff]+1);
                res = max(res,dp[j][diff]);
            }
        }
        return res;
    }
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();

        // vector<vector<int>> dp(nums.size()+1,vector<int>(1001,-1));
        // int ans=0;
        // for(int i=0; i<nums.size()-1; i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         // ans = max(ans,2+solve(i,nums[j] - nums[i],nums));
        //         ans = max(ans,2+solvemem(i,nums[j] - nums[i]+500,nums,dp));
        //     }
        // }
        // return ans;

        return solvetab(nums);
    }
};