//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

#define MOD 1000000007
class Solution{
    public:
    int add(int a,int b){

        return (a%MOD +b%MOD)%MOD;

    }

    int mul(int a,int b){

        return ((a%MOD)*1LL*(b%MOD))%MOD;

    }
    long long solve(int n,int k){
        if(n==1) return k;
        if(n==2) return add(k,mul(k,k-1));
        
        long long ans = add(mul(solve(n-2,k),k-1), mul(solve(n-1,k),k-1));
        
        return ans;
    }
      long long memSolve(int n, int k,vector< long long>&dp){

        if(n==1)

            return k;

        if(n==2)
            return add(k,mul(k,k-1));

        if(dp[n]!=-1)    

            return dp[n];

        dp[n]=add(mul(memSolve(n-2,k,dp),k-1),mul(memSolve(n-1,k,dp),k-1));

        return dp[n];

    }
    long long solvetab(int n,int k){
        vector<int> dp(n+1,-1);
        dp[1] = k;
        dp[2] = add(k,mul(k,k-1));
        
        for(int i=3; i<=n; i++){
            dp[i] = add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
        }
        
        return dp[n];
        
    }
    long long spaceoptimization(int n,int k){
        
        int prev2= k;
        int prev1 = add(k,mul(k,k-1));
        
        for(int i=3; i<=n; i++){
            int ans = add(mul(prev2,k-1),mul(prev1,k-1));
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    long long countWays(int n, int k){
        // code here
        //return solve(n,k);
        // vector<long long> dp(n+1,-1);
        // return memSolve(n,k,dp);
        // return solvetab(n,k);
        return spaceoptimization(n,k);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends