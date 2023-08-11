//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, int wt[], int val[], int index){
        
        //base case
        if(index == 0){
            if(wt[0] <= W){
                return val[0];
            }
            else return 0;
        }
        
        int include = 0;
        if(wt[index] <= W){
            include = val[index] + solve(W - wt[index],wt,val,index-1);
        }
        
        int exclude = 0 + solve(W,wt,val,index-1);
        
        int ans = max(include,exclude);
        
        return ans;

    }
    int solvemem(int W, int wt[], int val[], int index,vector<vector<int>>& dp){
        if(index == 0){
            if(wt[0] <= W){
                return val[0];
            }
            else return 0;
        }
        if(dp[index][W] != -1){
            return dp[index][W];
        }
        int include = 0;
        if(wt[index] <= W){
            include = val[index] + solvemem(W - wt[index],wt,val,index-1,dp);
        }
        
        int exclude = 0 + solvemem(W,wt,val,index-1,dp);
        
        // row and column are decided by  the amount of space given in the dp vector
        // as if maximum elements no is given in rows element then index will be in row 
        // if weight is given then the coloum will have W 
        dp[index][W] = max(include,exclude);
        
        return dp[index][W];
    }
    int solvetab(int W, int wt[], int val[], int n){
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        
        // second element is weight
        // if index is unchanged in next row then the value is not taken
        // the first element is smaller than the last W of the col 
        // then assigning the first row wt[0] if it is not taken then
        // the next row will have the same value
        // for the  

        // in prev base case all rows had 0 so there are weight size of coloums therefore wt[0] till W
        for(int i=wt[0]; i<=W; i++){
            if(wt[0] <= W){    // w should be i???
                dp[0][i] = val[0];
            }
            else dp[0][i] = 0;
        }
        
        for(int index = 1; index<n; index++){
            for(int i=0; i<=W; i++){
                int include = 0;
                // index-1 is used because the row element and prev col element is max is used for maximum
                // if the sum of weights is available then that value is given val[index] is added
                if(wt[index] <= i){
                    include = val[index] + dp[index-1][i-wt[index]];
                }
        
                int exclude = 0 + dp[index-1][i];
                
                dp[index][i] = max(include,exclude);
            }
        }
        return dp[n-1][W];
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   // Your code here
    //   return solve(W,wt,val,n);
    // vector<vector<int>> dp(n,vector<int>(W+1,-1));
    // return solvemem(W,wt,val,n-1,dp);
    return solvetab(W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends