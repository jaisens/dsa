class Solution {
public:
    bool solve(int index,vector<int>& nums,int target){
        // base case
        if(index >= nums.size()) return 0;
        if(target < 0) return 0;
        if(target == 0) return 1;

        bool inc = solve(index+1,nums,target-nums[index]);
        bool exc = solve(index+1, nums, target);

        return inc or exc;
    }

    bool solvemem(int index,vector<int>& nums,int target,vector<vector<int>>& dp){
        // base case
        if(index >= nums.size()) return 0;
        if(target < 0) return 0;
        if(target == 0) return 1;

        if(dp[index][target] != -1)
            return dp[index][target];

        
        bool inc = solvemem(index+1,nums,target-nums[index],dp);
        bool exc = solvemem(index+1, nums, target,dp);

        return dp[index][target] = inc or exc;
    }
    bool solvetab(int n,vector<int>& nums,int t){
        // int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(t+1,0));

        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        // instead of index starting from n we can start from n-1 
        // because of base case
        for(int index = n-1; index >=0; index--){
            for(int target = 0; target <= t; target++){
                bool inc=0;
                if(target-nums[index] >= 0)
                    inc = dp[index+1][target-nums[index]];

                bool exc = dp[index+1][target];

               dp[index][target] = inc or exc;
            }
        }
        return dp[0][t];
    }
    bool spaceoptimization(int n,vector<int>& nums,int t){
        vector<int> curr(t+1,0);
        vector<int> next(t+1,0);

        // see previous base cases
        curr[0]=1;
        next[0]=1;

        for(int index = n-1; index >=0; index--){
            for(int target = 0; target <= t; target++){
                bool inc=0;
                if(target-nums[index] >= 0)
                    inc = next[target-nums[index]];

                bool exc = next[target];

               curr[target] = inc or exc;
            }
            // make diagram and see the for loop working
            next=curr;
        }
        return next[t];

    }
    bool canPartition(vector<int>& nums) {
        int total=0;

        for(int i=0; i<nums.size(); i++){
            total+=nums[i];
        }

        if(total & 1) return 0;
        int target = total/2;

        // return solve(0,nums,target);
        
        // vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));

        // return solvemem(0,nums,target,dp);

        //return solvetab(nums.size(),nums,target);
        return spaceoptimization(nums.size(),nums,target);

    }
};