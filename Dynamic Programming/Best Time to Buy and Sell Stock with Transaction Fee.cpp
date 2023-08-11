// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 
class Solution {
public:
    int solvetab(vector<int>& prices,int fee){
        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit=0;
                if(buy==1){
                    profit += max((-prices[index] + dp[index+1][0]),(0 + dp[index+1][1]));
                }
                else{
                    profit += max((prices[index] + dp[index+1][1] -fee),(0 + dp[index+1][0]));
                }

                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solvetab(prices,fee);
    }
};

//just subtract fees when selling a stock