class Solution {
public:

    // longest arithmetic subsequence with common difference   [9,4,7,2,10] = [4,7,10]


    int solve(int index,int diff,vector<int>& nums){

        if(index < 0)
            return 0;

        int ans = 0;
        // going backwards to find all the elements will given difffernec
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

        // for loop isiliye hai taki we can skip some elements like in top down
        // crazy
        for(int i=index-1; i>=0; i--){
            if(nums[index]-nums[i] + 500 == diff){
                ans = max(ans,1+solvemem(i,diff,nums,dp));
            }
        }
        return dp[index][diff] = ans;
    }

    // TC = O(n^3) SC = o(n)
    int solvetab( vector<int>& nums){
        vector<vector<int>> dp(nums.size(),vector<int>(1001,1));
        // stores the maximum length till ith index with difference diff dp[i][diff]

        int res=1,diff;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){

                diff = nums[j] - nums[i] + 500;

                // if at jth index has been already proceseed and has some positive value then adding the ith element so +1 else the two elements will make a new subsequence so 2
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff]+1 : 2;
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
                    // adding two because 2 element ap to hota hi hai
                    // adding 500 because maximum element diff is 500 and we do not want negative index
        //         // ans = max(ans,2+solve(i,nums[j] - nums[i],nums));
        //         ans = max(ans,2+solvemem(i,nums[j] - nums[i]+500,nums,dp));
        //     }
        // }
        // return ans;

        return solvetab(nums);
    }
};