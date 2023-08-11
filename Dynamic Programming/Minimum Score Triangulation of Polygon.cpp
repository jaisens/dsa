class Solution {
public:
    int solve(vector<int>& v,int i,int j){
        //if the front and end index come side by side then no triangle can be formed 
        if(i+1==j) return 0;

        //elements exlcuding the first and last element can be used to make triangle hence 
        //loop for all those elements
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++){
            ans = min(ans,v[i]*v[k]*v[j] + solve(v,i,k) + solve(v,k,j));
        }
        return ans;
    }
    int solvemem(vector<int>& v,int i,int j,vector<vector<int>>&dp){
        //if the front and end index come side by side then no triangle can be formed 
        if(i+1==j) return 0;

        //elements exlcuding the first and last element can be used to make triangle hence 
        //loop for all those elements
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int k=i+1; k<j; k++){
            ans = min(ans,v[i]*v[k]*v[j] + solvemem(v,i,k,dp) + solvemem(v,k,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solvetab(vector<int>& v){
        
        int n = v.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        //it also handles the i+1==j base case as it avoids it 
        //to avoid and make use of the previous code it is written in this manner
        for(int i = n-1; i>=0; i--){
            // k will be in between the i and j
            // and j will increase from i+2 to n
            // three points will be available 
            
            for(int j = i+2; j<n; j++){
                int ans = INT_MAX;
                for(int k=i+1; k<j; k++){
                    ans = min(ans,v[i]*v[k]*v[j] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans; 
            }
        }
        //becuse in recursive solution i and j were returned which had vlaues 0 and n-1
        //in first loop
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        // int n = values.size();
        // return solve(values,0,n-1);
        // int n = values.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solvemem(values,0,n-1,dp);
        return solvetab(values);
    }
};