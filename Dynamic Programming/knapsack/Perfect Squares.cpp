class Solution {
public:

    // n is reducing so use squares that are less than the reduced n value hence it will not become negative
    int solve(int n,vector<int> &dp){
        if(n == 0) return 0;

        if(dp[n] != -1) return dp[n];
        
        int ans = n;
        // important condition
        for(int i=1; i*i<=n; i++){
            int temp = i*i;
            ans = min(ans,1+solve(n-temp,dp));
        }

        return dp[n] = ans;
        
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};