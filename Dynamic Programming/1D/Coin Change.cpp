class Solution {
public:
     int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
        //base case
        if(amount == 0) {
            return 0;
        }
        if(amount < 0 ) {
            return INT_MAX;
        }
        //ans already exists
        if(dp[amount] != -1) {
            return dp[amount];
        }

        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            int ans = solveMem(coins, amount - coins[i], dp);
            if(ans != INT_MAX) {
                mini = min(mini,1+ ans);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    // approach 2 - easy
    int solve(vector<int>& coins, int amount, int index,vector<vector<int>> &dp){
        if(index >= coins.size()){
            if(amount == 0){
                return 0;
            }
            return 1e8;
        }
        if(dp[amount][index] != -1) return dp[amount][index];

        int take = 1e8;
        if(amount - coins[index] >= 0){
            take = 1 + solve(coins,amount-coins[index],index,dp);
        }

        int nottake = solve(coins,amount,index+1,dp);

        return dp[amount][index] = min(take,nottake);
        
    }
    int coinChange(vector<int>& coins,int amount){
        vector<int> dp (amount+1,-1);
        int ans= solveMem(coins,amount,dp);
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }
};