// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

class Solution {
public:
    int solve(string &a,string &b,int i,int j){
        
        //the minimum incrementor will be less than its full length the operations will be calculated
        // by the recursive function the remaining words of the longer string will be needed to be deleted
        // hence the no of operations needs to added

        // the shorter lenght will end first
        if(a.length() == i) 
            return b.length()-j;

        if(b.length() == j)
            return a.length()-i;

        int ans=0;

        if(a[i] == b[j]){
            ans = solve(a,b,i+1,j+1);
        }
        else{
            // insert
            int insertans = 1 + solve(a,b,i,j+1);

            // delete
            int deleteans = 1 + solve(a,b,i+1,j);

            // replace

            int replaceans = 1 + solve(a,b,i+1,j+1);

            ans = min({insertans,deleteans,replaceans});
        }

        return ans;
    }
    int solvemem(string &a,string &b,int i,int j,vector<vector<int>>& dp){

        if(a.length() == i) 
            return b.length()-j;

        if(b.length() == j)
            return a.length()-i;

        if(dp[i][j] != -1) return dp[i][j];

        int ans=0;
        if(a[i] == b[j]){
            ans = solvemem(a,b,i+1,j+1,dp);
        }
        else{
            // insert
            int insertans = 1 + solvemem(a,b,i,j+1,dp);

            // delete
            int deleteans = 1 + solvemem(a,b,i+1,j,dp);

            // replace

            int replaceans = 1 + solvemem(a,b,i+1,j+1,dp);

            ans = min({insertans,deleteans,replaceans});
        }

        return dp[i][j] = ans;
    }
    int solvetab(string& a, string& b){
        int n = a.size();
        int m = b.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0; i<a.length(); i++){
            dp[i][b.length()] = a.length()-i;
        }

        // when i(aka a) reaches its maximum value all values of j will have the blength-j vlaue
        for(int j=0; j<b.length(); j++){
            dp[a.length()][j] = b.length()-j;
        }

        for(int i = n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){

                int ans=0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    // insert
                    int insertans = 1 + dp[i][j+1];

                    // delete
                    int deleteans = 1 + dp[i+1][j];

                    // replace

                    int replaceans = 1 + dp[i+1][j+1];

                    ans = min({insertans,deleteans,replaceans});
                }

                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int spaceoptimization(string& a, string& b){
        int n = a.size();
        int m = b.size();
        //  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        vector<int> next(m+1,0);
        vector<int> curr(m+1,0);

        for(int i=0; i<a.length(); i++){
            curr[b.length()] = a.length()-i;
        }

        // the last row element which is the next row
        for(int j=0; j<b.length(); j++){
            next[j] = b.length()-j;
        }

        for(int i = n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                
                // curr[b.length()] = a.length()-1;
                int ans=0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                else{
                    // insert
                    int insertans = 1 + curr[j+1];

                    // delete
                    int deleteans = 1 + next[j];

                    // replace

                    int replaceans = 1 + next[j+1];

                    ans = min({insertans,deleteans,replaceans});
                }

                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        // return solve(word1,word2,0,0);

        int n = word1.size();
        int m = word2.size();

        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solvemem(word1,word2,0,0,dp);

        return solvetab(word1,word2);
    }
};