class Solution {
public:
    // we can use edit distance approach or lcs approach
    int minimumDeleteSum(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();

        int c1 = 0, c2 = 0;

        for(auto i : s1){
            c1 += i;
        }

        for(auto i : s2){
            c2 += i;
        }

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1] + s1[i];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }

        int lcs = dp[0][0];

        return c1 - lcs + c2 - lcs;
    }
};