class Solution {
public:
    int solve(vector<int>& satisfaction,int index, int time){
        if(index == satisfaction.size()) return 0;

        int include = (time + 1)*satisfaction[index] + solve(satisfaction,index+1,time+1);
        int exclude = 0 + solve(satisfaction,index+1,time);

        return max(include,exclude);
    }
    int solvemem(vector<int>& satisfaction,int index, int time,vector<vector<int>> &dp){
        if(index == satisfaction.size()) return 0;

        if(dp[index][time] != -1) return dp[index][time];

        int include = (time + 1)*satisfaction[index] + solvemem(satisfaction,index+1,time+1,dp);
        int exclude = 0 + solvemem(satisfaction,index+1,time,dp);

        dp[index][time] = max(include,exclude);
        return dp[index][time];
    }
    int solvetab(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // not starting from n because it is zero from base case and already all elemets are zero
        for(int index = n-1; index >=0; index--){
            for(int time = index; time>=0; time--){
                int include = (time + 1)*satisfaction[index] +dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];

                dp[index][time] = max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int spaceoptimization(vector<int>& satisfaction){
        int n = satisfaction.size();

        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        for(int index = n-1; index >=0; index--){
            for(int time = index; time>=0; time--){
                int include = (time + 1)*satisfaction[index] +next[time+1];
                int exclude = 0 + next[time];

                curr[time] = max(include,exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction,0,0);
        int n = satisfaction.size();
        // vector<vector<int>> dp(n+1,vector<int> ( n+1,-1));
        // return solvemem(satisfaction,0,0,dp);
        return solvetab(satisfaction);
    }
};