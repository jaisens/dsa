class Solution {
public:
    //recursion
    int solverec(vector<int>& coins, int amount){
        
        if(amount == 0)
            return 0;
        
        //int max so that it can be distinguished
        if(amount<0)
            return INT_MAX;
        
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            //a coins is selected using the for loop and it is decreased form the amount 
            int ans = solverec(coins, amount-coins[i]);
            
            //int_max because a negative number might be present and INT_MAX may be returned
            if(ans != INT_MAX){
                //when coin is chosen then 1 is added as a coins is picke
                mini = min(mini,1+ans);
            }
        }
        return mini;
        
    }
    
    //recursion+memoization
    int changemem(vector<int>& dp, vector<int>& coins,int amt){
        if(amt == 0)
            return 0;

        if(amt < 0)
            return INT_MAX;

        if(dp[amt] != -1)
            return dp[amt];

        int mini = INT_MAX;

        for(int i=0; i<coins.size(); i++){
            int ans = changemem(dp,coins, amt - coins[i]);
            if(ans != INT_MAX){
                mini = min(mini,1+ans);
            }
        }

        dp[amt] = mini;

        return mini;
        
    }
    
    //tabulation
    int solvetab(vector<int> coins, int amount){
        
        vector<int> dp(amount+1, INT_MAX);
        
        int mini = INT_MAX;
        dp[0] = 0;
        
        //started from 1 because dp[0] value is already known 
        for(int i=1; i<=amount; i++){
            //each i is value that can be made using coins 1,2,3,4,5 at last dp[amount] will come and we can return that
            for(int j=0; j<coins.size(); j++){
            
            //i-coins[j] means reducing the value of the coin from the i(which is amount to be made using coins)
            //!= int max means that value is not preprocessed
            if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
            } 
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        //recursion
        // int ans = solverec(coins, amount);
        // if(ans == INT_MAX) return -1;
        // else return ans;
        
        //recursion+memoization
//         int n = coins.size();
        
//         vector<int> dp(amount+1,-1);
        
//         int ans = solvemem(coins,amount,dp);
//         if(ans == INT_MAX) return -1;
//         else return ans;
        
        //tabulation
        return solvetab(coins,amount);
    }
};