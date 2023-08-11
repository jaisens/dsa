class Solution {
public:
    bool solve(string &str, string& pattern, int i,int j){
        if(i<0 && j<0)
            return true;

        if(i>=0 && j<0)
            return false;
        
        if(i<0 && j>=0){
            for(int k=0; k<=j; k++){
                if(pattern[k] != '*')
                    return false;
            }
            return true;
        }

        // match
        if(str[i] == pattern[j] || pattern[j] == '?'){
            return solve(str,pattern,i-1,j-1);
        }
        else if(pattern[j] == '*'){
            return ( solve(str,pattern,i-1,j) || solve(str,pattern,i,j-1) );
        }
        else
            return false;
        

    }
    bool solvemem(string &str, string& pattern, int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0)
            return true;

        if(i>0 && j==0)
            return false;
        
        if(i==0 && j>0){
            for(int k=1; k<=j; k++){
                if(pattern[k-1] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // match
        if(str[i-1] == pattern[j-1] || pattern[j-1] == '?'){
            return dp[i][j] = solvemem(str,pattern,i-1,j-1,dp);
        }
        else if(pattern[j-1] == '*'){
            return dp[i][j] = ( solvemem(str,pattern,i-1,j,dp) || solvemem(str,pattern,i,j-1,dp) );
        }
        else
            return false;
    }
    int solvetab(string& str,string &pattern){
        vector<vector<int>> dp(str.size()+1,vector<int>(pattern.size()+1,0));

        dp[0][0] = true;

        // j=1 because we have increased the indexing
        for(int j=1; j<=pattern.size(); j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if(pattern[k-1] != '*')
                    flag = false;
                    break;
            }
            dp[0][j] = flag;
        }

        for(int i=1; i<=str.size(); i++){
            for(int j=1; j<=pattern.size(); j++){
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?'){
                     dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[j-1] == '*'){
                     dp[i][j] = ( dp[i-1][j] || dp[i][j-1] );
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[str.size()][pattern.size()];
    }
    int spaceoptimization(string& str,string &pattern){
        // vector<vector<int>> dp(str.size()+1,vector<int>(pattern.size()+1,0));


        vector<int> prev(pattern.size()+1,0);
        vector<int> curr(pattern.size()+1,0);

        prev[0] = true;

        // j=1 because we have increased the indexing
        for(int j=1; j<=pattern.size(); j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if(pattern[k-1] != '*')
                    flag = false;
                    break;
            }
            prev[j] = flag;
        }

        for(int i=1; i<=str.size(); i++){
            for(int j=1; j<=pattern.size(); j++){
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?'){
                     curr[j] = prev[j-1];
                }
                else if(pattern[j-1] == '*'){
                     curr[j] = ( prev[j] || curr[j-1] );
                }
                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[pattern.size()];
    }
    bool isMatch(string s, string p) {
    //    return solve(s,p,s.size()-1,p.size()-1); 
    //    int n =s.size();
    //    int m=p.size();

    //    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //    return solvemem(s,p,s.size(),p.size(),dp);
    // //    converting to 1 index code
            // return solvetab(s,p);
            return spaceoptimization(s,p);
    }
};