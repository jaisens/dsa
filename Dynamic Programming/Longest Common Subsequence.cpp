// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

class Solution {
public:
    int solve(string a, string b,int i,int j){
        if(i == a.size()) return 0;
        if(j ==b.size()) return 0;

        int ans=0;
        if(a[i] == b[j]){
            ans =  1 + solve(a,b,i+1,j+1);
        }
        else{
            // either of them will be incremented and max will be stored 
            // not ans += because in previous condition 1 +  is added and the value is returned
            ans = max(solve(a,b,i+1,j),solve(a,b,i,j+1));
        }
        return ans;
    }
    int solvemem(string& a, string& b,int i,int j,vector<vector<int>>& dp){
        if(i == a.size()) return 0;
        if(j ==b.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans=0;
        if(a[i] == b[j]){
            ans =  1 + solvemem(a,b,i+1,j+1,dp);
        }
        else{
            ans = max(solvemem(a,b,i+1,j,dp),solvemem(a,b,i,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int solvetab(string &a, string& b){

        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){

                int ans=0;
                if(a[i] == b[j]){
                    ans =  1 + dp[i+1][j+1];
                }
                else{
                    ans = max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
    int spaceoptimization(string &a, string& b){
        
        // space compx can be minimum of n,m as i and j are loops so the first one to end will have the processing 
        // done so the next row can be processed
        int n = a.size();
        int m = b.size();

        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        vector<int> next(m+1,0);
        vector<int> curr(m+1,0);

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){

                int ans=0;
                if(a[i] == b[j]){
                    ans =  1 + next[j+1];
                }
                else{
                    ans = max(next[j],curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return solve(text1,text2,0,0);

        int n = text1.size();
        int m = text2.size();

        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solvemem(text1,text2,0,0,dp);

        // return solvetab(text1,text2);
        return spaceoptimization(text1,text2);
    }
};