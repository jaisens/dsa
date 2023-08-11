class Solution {
public:
    int solve(map<pair<int,int>,int> &maxi,vector<int>& arr,int start,int end){
        if(start == end) return 0;

        int ans = INT_MAX;
        for(int i=start; i<end; i++){
            ans = min(ans,maxi[{start,i}]*maxi[{i+1,end}] + solve(maxi,arr,start,i) + solve(maxi,arr,i+1,end));
        }

        return ans;
    }
    int solvemem(map<pair<int,int>,int> &maxi,vector<int>& arr,int start,int end,vector<vector<int>>& dp){
        if(start == end) return 0;

        if(dp[start][end] != -1) return dp[start][end];

        int ans = INT_MAX;
        for(int i=start; i<end; i++){
            ans = min(ans,maxi[{start,i}]*maxi[{i+1,end}] + solvemem(maxi,arr,start,i,dp) + solvemem(maxi,arr,i+1,end,dp));
        }

        return dp[start][end] = ans;
    }

    int solvetab(map<pair<int,int>,int> &maxi,vector<int> & arr){
        int n = arr.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));


        for(int start = n-1; start >=0; start--){
            for(int end = start; end <=n; end++){
                if(start == end) continue;
                else
                {   int ans = INT_MAX;
                    for(int i=start; i<end; i++){
                        ans = min(ans,maxi[{start,i}]*maxi[{i+1,end}] + dp[start][i] + dp[i+1][end]);
                    }
                    dp[start][end] = ans;
                }
            }
        }

        return dp[0][n];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;

        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
            }
        }

        // return solve(maxi,arr,0,arr.size()-1);
        // int n = arr.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solvemem(maxi,arr,0,arr.size()-1,dp);

        return solvetab(maxi,arr);
    }
};