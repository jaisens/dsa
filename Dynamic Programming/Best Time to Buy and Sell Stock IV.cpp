// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
// Find the maximum profit you can achieve. You may complete at most k transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

class Solution {
public:
    int solve(int index,int operationno,int k, vector<int>& prices){
        if(index == prices.size()) return 0;

        if(operationno == 2*k) return 0;

        int profit = 0;
        if(operationno%2 == 0){
            profit += max((-prices[index] + solve(index+1,operationno+1,k,prices)),(0 + solve(index+1,operationno,k,prices)));
        }
        else{
            profit += max((prices[index] + solve(index+1,operationno+1,k,prices)),(0 + solve(index+1,operationno,k,prices)));
        }

        return profit;
    }
    int solvemem(int index,int operationno,int k, vector<int>& prices,vector<vector<int>>& dp){
        if(index == prices.size()) return 0;

        if(operationno == 2*k) return 0;

        if(dp[index][operationno] != -1) return dp[index][operationno];

        int profit = 0;
        if(operationno%2 == 0){
            profit += max((-prices[index] + solvemem(index+1,operationno+1,k,prices,dp)),(0 + solvemem(index+1,operationno,k,prices,dp)));
        }
        else{
            profit += max((prices[index] + solvemem(index+1,operationno+1,k,prices,dp)),(0 + solvemem(index+1,operationno,k,prices,dp)));
        }

        return dp[index][operationno] = profit;
    }
    int solvetab(int k, vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

        for(int index = n-1; index>=0; index--){
            for(int operationno = 0; operationno <2*k; operationno++){
                int profit = 0;
                if(operationno%2 == 0){
                    profit += max((-prices[index] + dp[index+1][operationno+1]),(0 + dp[index+1][operationno]));
                }
                else{
                    profit += max((prices[index] + dp[index+1][operationno+1]),(0 + dp[index+1][operationno]));
                }

                dp[index][operationno] = profit;
            }
        }

        return dp[0][0];
    }
    int spaceoptimization(int k, vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

        vector<int> next(2*k+1,0);
        vector<int> curr(2*k+1,0);

        for(int index = n-1; index>=0; index--){
            for(int operationno = 0; operationno <2*k; operationno++){
                int profit = 0;
                if(operationno%2 == 0){
                    profit += max((-prices[index] + next[operationno+1]),(0 + next[operationno]));
                }
                else{
                    profit += max((prices[index] + next[operationno+1]),(0 + next[operationno]));
                }

                curr[operationno] = profit;
            }
            next = curr;
        }

        return next[0];
    }
    int maxProfit(int k, vector<int>& prices) {
        // return solve(0,0,k,prices);

        int n = prices.size();
        // vector<vector<int>> dp(n,vector<int>(2*k,-1));
        // return solvemem(0,0,k,prices,dp);

        // return solvetab(k,prices);
        return spaceoptimization(k,prices);

        //each buy and sell are counted and when operationno is even buy and when odd sell
    }
};