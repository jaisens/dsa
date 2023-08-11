#include<bits/stdc++.h>
int solve(int n,int x,int y,int z){
    if(n == 0)
        return 0;
    if(n < 0)
        return INT_MIN;   //int_min so the that path can be neglected as it cannot be used for solution
        //-1 is not used because it will cancel with the +1 can cause errors henvce int_minn is used
    
    //when a cut it made its length is added to the orignal hence +1
    int a = solve(n-x,x,y,z) + 1;
    int b = solve(n-y,x,y,z) + 1;
    int c = solve(n-z,x,y,z) + 1;
    
    int ans = max(a,max(b,c));
    return ans;
}
int solvemem(int n,int x,int y,int z,vector<int> dp){
    if(n==0) return 0;
    if(n<0) return INT_MIN;
    
    if(dp[n] != -1){
        return dp[n];
    }
    z
    int a = solvemem(n-x,x,y,z,dp) + 1;
    int b = solvemem(n-y,x,y,z,dp) + 1;
    int c = solvemem(n-z,x,y,z,dp) + 1;
    
    dp[n] = max(a,max(b,c));
    return dp[n];
}
int solvetab(int n,int x,int y,int z){
    vector<int> dp(n+1,INT_MIN);
    dp[0]=0;
    
    //max is only used in tabulation becaise in previous quesiton the value is overridden if new and it is
    //made from max value only hence it is maximum value
    for(int i=1; i<=n; i++){
        //max because dp[i] can be made from sum x,y or z hence to get maximum 
        // checking if it was to come from x would it be maximum
        
        if(i-x>=0) dp[i] =max(dp[i],dp[i-x] + 1);    //max is used because a new path can be made from the same node
                                                    //as it can have a value from before hence max
        if(i-y >= 0) dp[i] = max(dp[i],dp[i-y] + 1);
        if(i-z >= 0) dp[i] = max(dp[i],dp[i-z] + 1);
    }
    
    return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	
    vector<int> dp(n+1,-1);
    int ans = solvetab(n,x,y,z);
    if(ans<0) return 0;   //checking if negative element is returned
    else return ans;
    
    
    
    
    
    
    
    
}