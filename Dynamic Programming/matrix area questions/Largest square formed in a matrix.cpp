//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>>& mat,int i,int j,int maxi){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        int right = solve(mat,i,j+1,maxi);
        int diagonal = solve(mat,i+1,j+1,maxi);
        int down = solve(mat,i+1,j,maxi);
        
        
        int ans ;
        if(mat[i][j] == 1){
            //
            // ans fidns the size of square that can be formed and maxi stores maximum of those
            ans = 1 + min({right,diagonal,down});
            maxi = max(maxi,ans);
            //returning ans not maxi because we have to return no of elements to left right and down
            //maxi is the answer
            return ans;
        }
        else{
            return 0;
        }
    }
    int solvemem(vector<vector<int>>& mat,int i,int j,int &maxi,vector<vector<int>>& dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = solvemem(mat,i,j+1,maxi,dp);
        int diagonal = solvemem(mat,i+1,j+1,maxi,dp);
        int down = solvemem(mat,i+1,j,maxi,dp);
        
        
        int ans ;
        if(mat[i][j] == 1){
            
            // for ans dp is used because it is used again for many values
            dp[i][j] = 1 + min({right,diagonal,down});
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
    int solvetab(vector<vector<int>>& mat,int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        
        // bottom up
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--){
               
        
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                
                int ans ;
                if(mat[i][j] == 1){
                    //
                    dp[i][j] = 1 + min({right,diagonal,down});
                    maxi = max(maxi,dp[i][j]);
                    
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[0][0];
    }
    int spaceoptimization(vector<vector<int>>& mat,int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        
        //vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        vector<int> curr(col+1,0);
        vector<int> next(col+1,0);
        
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--){
               
        
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                
                int ans ;
                if(mat[i][j] == 1){
                    //
                    curr[j] = 1 + min({right,diagonal,down});
                    maxi = max(maxi,curr[j]);
                    
                }
                else{
                    curr[j]=0;
                }
            }
            next = curr;
        }
        return next[0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        // int maxi = 0;
        // solve(mat,0,0,maxi);
        // return maxi;
        // int maxi = 0;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // solvemem(mat,0,0,maxi,dp);
        // return maxi;
        // int maxi = 0;
        // solvetab(mat,maxi);
        // return maxi;
        int maxi = 0;
        spaceoptimization(mat,maxi);
        return maxi;
    }
};

// intuitive solution
int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
        int ret = 0;
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                if(matrix[i-1][j-1] == '0'){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return ret*ret;
    }