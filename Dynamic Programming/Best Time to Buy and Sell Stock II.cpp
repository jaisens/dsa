// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

class Solution {
public:
    int solve(int index,int buy,vector<int>& prices){
        if(index == prices.size()){
            return 0;
        }

        int profit=0;
        if(buy==1){
            profit += max((-prices[index] + solve(index+1,0,prices)),(0 + solve(index+1,1,prices)));
        }
        else{
            profit += max((prices[index] + solve(index+1,1,prices)),(0 + solve(index+1,0,prices)));
        }

        return profit;
    }
    int solvemem(int index,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(index == prices.size()){
            return 0;
        }
        
        if(dp[index][buy] != -1) return dp[index][buy];

        int profit=0;
        if(buy==1){
            profit += max((-prices[index] + solvemem(index+1,0,prices,dp)),(0 + solvemem(index+1,1,prices,dp)));
        }
        else{
            profit += max((prices[index] + solvemem(index+1,1,prices,dp)),(0 + solvemem(index+1,0,prices,dp)));
        }

        return dp[index][buy] = profit;
    }
    int solvetab(vector<int>& prices){
        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit=0;
                if(buy==1){
                    profit += max((-prices[index] + dp[index+1][0]),(0 + dp[index+1][1]));
                }
                else{
                    profit += max((prices[index] + dp[index+1][1]),(0 + dp[index+1][0]));
                }

                dp[index][buy] = profit;
            }
        }

        return dp[0][1];   // return that is sent in memoization intially because it is in reverse so final answer will be stored there
    }
    int spaceoptimization(vector<int>& prices){
        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2,0));

        vector<int> curr(2,0);
        vector<int> next(2,0);
        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit=0;
                if(buy==1){
                    profit += max((-prices[index] + next[0]),(0 + next[1]));
                }
                else{
                    profit += max((prices[index] + next[1]),(0 + next[0]));
                }

                curr[buy] = profit;
            }
            next = curr;  // copy into next one
        }

        return next[1];  //return the next 
    }

    int maxProfit(vector<int>& prices) {
        // return solve(0,1,prices);

        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return solvemem(0,1,prices,dp);

        // return solvetab(prices);
        return spaceoptimization(prices);
    }
};