#include <bits/stdc++.h> 
int solve(vector<int> &nums, int n){
    //base case
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];
    
    int inc = solve(nums,n-2) + nums[n];
    int exc = solve(nums,n-1) + 0;
    
    return max(inc,exc);
}
int solvemem(vector<int>& nums,vector<int>& dp,int n){
    if(n < 0)
        return 0;
    
    if(n==0)
        return nums[0];
    
    if(dp[n] != -1)
        return dp[n];
    
    int inc = solvemem(nums,dp,n-2) + nums[n];
    int exc = solvemem(nums,dp,n-1) + 0;
    
    dp[n] = max(inc,exc);
    //n-1 is sent from the function call hence n can be used to get last element
    return dp[n];
    
}
// usually tab goes in reverse order of memoization using for loop
int solvetab(vector<int>& nums){
    
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];
    
    for(int i=1; i<n; i++){
        //better optimization in space optimiszation method
        int inc = dp[i-2] + nums[i];
        int exc = dp[i-1];
        dp[i] = max(inc,exc);
    }
    
    return dp[n-1];       
}
int spaceoptimization(vector<int>& nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    
    for(int i=1; i<n; i++){
        int take = nums[i];
        if(i>1) take += prev2;      //when taking the currenet element then prev2 will also be taken 
        int nontake = 0 + prev;      //when current is not taken then the prev will be taken 
        int ans = max(take,nontake);
        prev2=prev;
        //also as 
        prev=ans;         //ans is stored in prev hence return ans
    }
    
    return prev; 
}
int maximumNonAdjacentSum(vector<int> &nums){
    
//     int n = nums.size();
//     int ans = solve(nums,n-1);
//     return ans;
    
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return solvemem(nums,dp,n-1);
    
//     return solvetab(nums);
    
    return spaceoptimization(nums);
    
    
    
    
    
}