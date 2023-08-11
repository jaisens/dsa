class Solution {
public:
    int solve(int n,vector<int>& nums, int curr,int prev){
        if(curr == n) return 0;

        //include
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1 + solve(n,nums,curr+1,curr);
        }

        // exclude
        int nottake = 0 + solve(n,nums,curr+1,prev);

        return max(take,nottake);
    }
    int solvemem(int n,vector<int>& nums, int curr,int prev,vector<vector<int>> & dp){
        if(curr == n) return 0;
        // prev 1 because it starts from -1;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        //include
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1 + solvemem(n,nums,curr+1,curr,dp);
        }

        // exclude
        int nottake = 0 + solvemem(n,nums,curr+1,prev,dp);

        return dp[curr][prev+1] = max(take,nottake);
    }
    int solvetab(int n,vector<int>& nums){
        // int n = nums.size();
        // dont forget intiallizing with 0 because 1 +  is added and gives wrong answer
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                
                int take = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    //curr+1 in prev col
                    take = 1 + dp[curr+1][curr+1];
                }

                // exclude
                // prev+1 in prev col
                int nottake = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(take,nottake);
            }
        }
        // dp[0][-1+1];
        return dp[0][0]; 
    }
    int spaceoptimization(int n,vector<int>& nums){

        vector<int> currrow(n+1,0);
        vector<int> nextrow(n+1,0);

        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                
                int take = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    //curr+1 in prev col
                    //curr+1 == next row
                    take = 1 + nextrow[curr+1];
                }

                // exclude
                // prev+1 in prev col
                int nottake = 0 + nextrow[prev+1];

                // curr == curr row
                currrow[prev+1] = max(take,nottake);
            }
            nextrow = currrow;
        }
        // dp[0][-1+1];
        return nextrow[0];
    }

    int solveoptimal(vector<int>& nums){
        if(nums.size() == 0) return 0;

        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > ans.back()) ans.push_back(nums[i]);
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i])- ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return solve(n,nums,0,-1);
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solvemem(n,nums,0,-1,dp);
        // return solvetab(n,nums);
        return spaceoptimization(n,nums);
    }
};