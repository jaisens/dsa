
// a pair can be taken if [a,b] [c,d] b<c

// TC = O(n^2) SC = O(n)

int solvetab(vector<vector<int>> & pairs){
        int n = pairs.size();
        vector<int> dp(n,1);

        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i],1+dp[j]);
                    ans = max(ans,dp[i]);
                }
            }
        }

        return ans;
    }

int findLongestChain(vector<vector<int>>& pairs) {

    // sort the pairs
    sort(pairs.begin(),pairs.end());
    // int n = pairs.size();
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return solve(pairs,0,-1,dp);

    return solvetab(pairs);
}