class Solution {
public:

    // see notes
    static bool compare(vector<int>&a , vector<int>&b){
        if(a[0]==b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int solveoptimal(vector<vector<int>>& nums){
        if(nums.size() == 0) return 0;

        vector<int> ans;
        ans.push_back(nums[0][1]);
        for(int i=0; i<nums.size(); i++){
            if(nums[i][1] > ans.back()) ans.push_back(nums[i][1]);
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i][1])- ans.begin();
                ans[index] = nums[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),compare);

        return solveoptimal(envelopes);
    }
};