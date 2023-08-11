class Solution {
public:
    int solve(int n){
        if(n==0) return 0;

        //because in worst case only 1^2 will be used and no of squares used will be n
        int ans = n;
        for(int i=1; i*i<=n; i++){
            int temp = i*i;
            ans = min(ans,1+solve(n-temp));
        }

        return ans;
    }
    int solvemem(int n,vector<int>& dp){
        if(n==0) return 0;

        if(dp[n] != -1) return dp[n];

        int ans = n;
        for(int i=1; i*i<=n; i++){
            int temp = i*i;
            ans = min(ans,1+solvemem(n-temp,dp));
        }
        dp[n] = ans;

        return dp[n];
    }
    int solvetab(int n){
        //using int max because each nth dp value is dependent on other values and min is used 
        //if -1 is present then it may cause problem
        //in mem is not used because there dp is only used for storing values
        vector<int> dp(n+1,INT_MAX);

        dp[0]=0;

        //outside call is for dp values and incrementing dp index
        //inside call is for calculating values for the current index from prev indexes
        //here i is working as n and j as (1-sqrt(n)) checker
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=n; j++){
                int temp = j*j;
                if(i-temp>=0)
                    dp[i] = min(dp[i],1+dp[i-temp]);
            }
        }

        return dp[n];
    }
    int numSquares(int n) {
        // return solve(n);
        // vector<int> dp(n+1,-1);
        // return solvemem(n,dp);
        return solvetab(n);
    }
};