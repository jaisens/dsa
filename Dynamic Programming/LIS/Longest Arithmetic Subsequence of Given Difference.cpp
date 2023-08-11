class Solution {
public:
    // int solve(vector<int>& arr, int difference, int prev, int curr,vector<vector<int>> &dp){
    //     if(curr >= arr.size()) return 0;

    //     int take = 0;
    //     if(prev == -1 || arr[curr] - arr[prev] == difference){
    //         take = 1 + solve(arr,difference,curr,curr+1);
    //     }
    //     int nottake = solve(arr,difference,prev,curr+1);

    //     return max(take,nottake);
    // }

    // TC = O(n^2) SC = O(n) Time Limit Exceeded
    int solvetab(vector<int>& arr, int difference){
        int n = arr.size();
        vector<int> dp(n,1);

        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i] - arr[j] == difference){
                    dp[i] = max(dp[i],dp[j]+1);
                    ans = max(ans,dp[i]);
                }
            }
        }

        return ans;

    }

    // used map to find the element 
    // TC = O(n) SC = O(n)
    
    int longestSubsequence(vector<int>& arr, int difference) {
        

        // vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        // return solve(arr,difference,-1,0,dp);

        // return solvetab(arr,difference);

        int n = arr.size();

        unordered_map<int,int> dp;

        int ans = 1;

        for(int i=0; i<n; i++){
            int num = arr[i];
            if(dp.find(num - difference) != dp.end()){
                dp[num] = dp[num - difference] + 1;
            }
            else{
                dp[num] = 1;
            }
            ans = max(ans,dp[num]);
        }

        return ans;
    }
};