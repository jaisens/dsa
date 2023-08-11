#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
    cin>>n;
    
    //step 1:
    vector<int> dp(n+1);
    
    //step 2: assign base case values
    dp[0] = 0;
    dp[1] = 1;
    
    //step 3: for loops from 2 to n
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n];
    
}