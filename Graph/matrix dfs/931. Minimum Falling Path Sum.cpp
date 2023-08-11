class Solution {
public:
    // TC - O(nm) SC - O(nm)
    int dfs(vector<vector<int>>& matrix, int i,int j,vector<vector<int>> &dp){
        if(i == matrix.size()-1 && j < matrix[0].size() && j >= 0){
            return matrix[i][j];
        }

        if(i> matrix.size() || j >= matrix[0].size() || j < 0) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        int leftchild = dfs(matrix,i+1,j-1,dp);
        int rightchild = dfs(matrix,i+1,j+1,dp);
        int bottomchild = dfs(matrix,i+1,j,dp);

        return dp[i][j] =  matrix[i][j] + min({leftchild,rightchild,bottomchild});        
    }

    // same tc ans sc
    int solvetab(vector<vector<int>>& matrix){

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0; i<m; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<matrix[0].size(); j++){
                // consider edge cases because it is going out of bound and no way to restrict is like memoization
                if(j == 0){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j == m-1){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = matrix[i][j] + min({dp[i-1][j],dp[i-1][j+1],dp[i-1][j-1]});
                }
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<m; i++){
            ans = min(ans,dp[n-1][i]);
        }

        return ans;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        // int n = matrix.size();
        // int m = matrix[0].size();
        // int ans = INT_MAX;

        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // for(int i=0; i<m; i++){
        //     ans = min(ans,dfs(matrix,0,i,dp));
        // }

        // return ans;

        return solvetab(matrix);
    }
};