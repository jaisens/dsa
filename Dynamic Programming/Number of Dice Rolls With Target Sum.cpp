#define M 1000000007 
class Solution {
public:
    int solve(int dice,int faces, int target){
        // base case
        if(target < 0) return 0;
        if(dice==0 && target!=0) return 0;
        if(target==0 && dice!=0) return 0;
        if(target==0 && dice==0) return 1;

        int ans=0;
        for(int i=1; i<=faces; i++){
            ans += solve(dice-1,i,target-i);
        }

        return ans%M;

    }
    int solvemem(int dice,int faces, int target,vector<vector<int>>&dp){
        // base case
        if(target < 0) return 0;
        if(dice==0 && target!=0) return 0;
        if(target==0 && dice!=0) return 0;
        if(target==0 && dice==0) return 1;

        if(dp[dice][target] != -1){
            return dp[dice][target];
        }
        int ans=0;
        for(int i=1; i<=faces; i++){
            ans = (ans%M + solvemem(dice-1,faces,target-i,dp)%M)%M;
        }
        dp[dice][target] = ans;
        return dp[dice][target];

    }
    int solvetab(int d, int f,int t){
        vector<vector<int>> dp(d+1,vector<int>(t+1,0));

        dp[0][0] = 1;

        // starting from 1 because 0 case is already taken
        for(int dice=1; dice<=d; dice++){
            for(int target=1; target<=t; target++){
                int ans=0;
                for(int i=1; i<=f; i++){
                    if(target-i>=0)
                        ans = (ans%M + (dp[dice-1][target-i])%M)%M;
                }
                dp[dice][target]=ans;
            }
        }
        return dp[d][t];
    }
    int spaceoptimization(int d,int f,int t){
        vector<int> prev(t+1,0);
        vector<int> curr(t+1,0);

        prev[0]=1;

        for(int dice=1; dice<=d; dice++){
            for(int target=1; target<=t; target++){
                int ans=0;
                for(int i=1; i<=f; i++){
                    if(target-i>=0)
                        ans = (ans%M + (prev[target-i])%M)%M;
                }
                curr[target]=ans;
            }
            // here prev=curr because when target loop completes the row is made 
            // completely
            prev=curr;
        }
        // prev is returned because after processing the last row it is stored
        // in prev
        return prev[t];

    }
    int numRollsToTarget(int n, int k, int target) {
        //return solve(n,k,target)%M;
        // vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        // return solvemem(n,k,target,dp);
        return solvetab(n,k,target);
    }
};