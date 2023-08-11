class Solution {
public:
    int solve(vector<int>& cost, int n){
        
        if(n == 0)
            return cost[0];
        
        if(n == 1)
            return cost[1];
        
        //adding cost now to because each stair has a cost
        //2 minimums
        int ans = cost[n] + min(solve(cost, n-1), solve(cost,n-2));
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        //2 minimums because cost of the last step is not given is not to be added 
        //hence if we use 2 min we can add the cost of the current steps for the below steps and
        //not the current step
        int ans = min(solve(cost,n-1), solve(cost,n-2));
        return ans;
        
    }
};