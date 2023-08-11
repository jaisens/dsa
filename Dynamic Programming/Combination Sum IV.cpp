class Solution {
public:

    int solve(vector<int>& nums,int target){
        if(target<0) return 0;
        if(target==0) return 1;

        int ans = 0;
        //traversing through the array and subracting values form target all cases can be visualized
        // if answer is not found then 0 is returned and that path is not taken into ans
        for(int i=0; i<nums.size(); i++){
            ans += solve(nums,target-nums[i]);
        }
        return ans;
    }
    int solvemem(vector<int>& nums,int target,vector<int>&dp){
        if(target<0) return 0;
        if(target==0) return 1;
        
        if(dp[target] != -1) return dp[target];

        int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans += solvemem(nums,target-nums[i],dp);
        }

        dp[target] = ans;
        return dp[target];
    }
    int solvetab(vector<int>& nums, int target){
        vector<unsigned int> dp(target+1,0);
        
        dp[0] = 1;

        for(int i=1; i<=target; i++){
            for(int j=0; j<nums.size(); j++){
                if(i-nums[j]>=0)
                    dp[i] += dp[i-nums[j]];
            }
        }

        return dp[target];
    }
    //cannot be space optiized bceause dp[i] is dependent on nums[j]
    int combinationSum4(vector<int>& nums, int target) {
        // return solve(nums,target);
        // vector<int> dp(target+1,-1);
        // return solvemem(nums,target,dp);
        return solvetab(nums,target);
    }
};