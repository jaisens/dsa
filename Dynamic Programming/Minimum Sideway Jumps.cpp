class Solution {
public:

    int solve(vector<int>& obstacles,int currlane,int currpos){
        //if reached last lane
        if(currpos == obstacles.size()-1) return 0;

        // if there is no obstacle in front of the frog in the same lane
        if(obstacles[currpos+1] != currlane){
            return solve(obstacles,currlane,currpos+1);
        }
        else{
            //for jumping sideways
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                // currlane != i means that it should not be equal to current lane
                // and there should be no obstacles in the lane
                if(currlane != i && obstacles[currpos] != i)
                    // min of all the paths
                    ans = min(ans,1+solve(obstacles,i,currpos));
            }
            return ans;
        }
    }
    int solvemem(vector<int>& obstacles,int currlane,int currpos,vector<vector<int>>& dp){
        //if reached last lane
        if(currpos == obstacles.size()-1) return 0;

        if(dp[currlane][currpos]  != -1) return dp[currlane][currpos];

        // if there is no obstacle in front of the frog in the same lane
        if(obstacles[currpos+1] != currlane){
            return solvemem(obstacles,currlane,currpos+1,dp);
        }
        else{
            //for jumping sideways
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                // currlane != i means that it should not be equal to current lane
                // and there should be no obstacles in the lane
                if(currlane != i && obstacles[currpos] != i)
                    // min of all the paths
                    ans = min(ans,1+solvemem(obstacles,i,currpos,dp));
            }
            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }
    int solvetab(vector<int>& obstacles){
        int n = obstacles.size();
        vector<vector<int>> dp(4,vector<int>(obstacles.size(),INT_MAX));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int currpos = n-1; currpos>=0; currpos--){
            for(int currlane = 1; currlane <= 3; currlane++ ){
                
                if(obstacles[currpos+1] != currlane){
                    dp[currpos][currlane] = dp[currlane][currpos+1];
                }
                else{
                   
                    int ans = INT_MAX;
                    for(int i=1; i<=3; i++){
                        if(currlane != i && obstacles[currpos] != i)
                            //** currpos +1 because in bottom up reverse everything is calc from back
                            //when we are checking form where sideways jump is made then
                            //we cannot use the currpos because it int_max value so its next element is
                            // used which is evaluated
                            //if more lanes are givevvn then that postion will also be checkede for obstacles

                            ans = min(ans,1+dp[i][currpos+1]);
                    }
                    dp[currlane][currpos] = ans;
                }
            }
        }

        return min({dp[2][0],1+dp[1][0],3+dp[3][0]});
    }
    int spaceoptimization(vector<int>& obstacles){
        
        //why size-1;
        int n = obstacles.size()-1;
        vector<int> curr(4,INT_MAX);
        vector<int> next(4,INT_MAX);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int currpos = n-1; currpos>=0; currpos--){
            for(int currlane = 1; currlane <= 3; currlane++ ){
                
                if(obstacles[currpos+1] != currlane){
                    curr[currlane] = next[currlane];
                }
                else{
                   
                    int ans = INT_MAX;
                    for(int i=1; i<=3; i++){
                        if(currlane != i && obstacles[currpos] != i)
                        //where currpos+1 is present put next and where it isnt put curr
                            ans = min(ans,1+next[i]);
                    }
                    curr[currlane] = ans;
                }
            }
            next = curr;
        }

        return min({next[2],1+next[1],1+next[3]});
    }
    int minSideJumps(vector<int>& obstacles) {
        // int n = obstacles.size();
        // return solve(obstacles,2,0);
        vector<vector<int>> dp(4,vector<int>(obstacles.size(),-1));
        return solvemem(obstacles,2,0,dp);
    }
};