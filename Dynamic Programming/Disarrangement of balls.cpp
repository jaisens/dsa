//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007
class Solution{
public:
    long int solve(int n){
        if(n==1) return 0;
        if(n==2) return 1;
        
    int ans = ((((n-1)%MOD)*((solve(n-1)%MOD) + (solve(n-2)%MOD)))%MOD);
        
        return ans;
    }
    long int solvemem(int n,vector<long int>& dp){
        if(n==1) return 0;
        if(n==2) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        
        dp[n]  = ((((n-1)%MOD)*((solvemem(n-1,dp)%MOD) + (solvemem(n-2,dp)%MOD)))%MOD);
        
        return dp[n];
    }
    long int solvetab(int n){
        vector<int> dp(n+1,-1);
        dp[1] = 0;
        dp[2] = 1;
        
        for(int i=3; i<=n; i++){
            long int first = dp[i-1]%MOD;
            long int second = dp[i-2]%MOD;
            long int ans = ((((i-1)%MOD)*(first+second))%MOD);
            dp[i] = ans;
        }
        
        return dp[n];
    }
    long int spaceoptimization(int n){
        int prev2=0;
        int prev1=1;
        
        for(int i=3;i<=n; i++){
            long int first = prev1%MOD;
            long int second = prev2%MOD;
            long int ans = ((((i-1)%MOD)*(first+second))%MOD);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
    long int disarrange(int N){
        // code here
        // vector<long int> dp(N+1,-1);
        // return solvemem(N,dp);
        //return solve(N);
        return spaceoptimization(N);
        return solvetab(N);
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends