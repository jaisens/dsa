// Given a string s, find the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


class Solution {
public:
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
    int longestPalindromeSubseq(string s) {
        string revstr = s;
        reverse(revstr.begin(),revstr.end());
        return spaceoptimization(s,revstr);
    }
};

// reverse the string and find the longest common subsequence 