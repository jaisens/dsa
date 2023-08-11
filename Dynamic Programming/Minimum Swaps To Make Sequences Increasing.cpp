class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped){

        // base case
        if(index == nums1.size()) return 0;

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swapped){
            swap(prev1,prev2);
        }

        // no swap
        int ans = INT_MAX;
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solve(nums1,nums2,index+1,0);
        }

        // swap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans,1+solve(nums1,nums2,index+1,1));
        }

        return ans;
    }
    int solvemem(vector<int>& nums1, vector<int>& nums2,int index,bool swapped,vector<vector<int>>& dp){

        // base case
        if(index == nums1.size()) return 0;

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swapped){
            swap(prev1,prev2);
        }

        if(dp[index][swapped] != -1) return dp[index][swapped];
        // no swap
        int ans = INT_MAX;
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solvemem(nums1,nums2,index+1,0,dp);
        }

        // swap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans,1+solvemem(nums1,nums2,index+1,1,dp));
        }

        return dp[index][swapped] = ans;
    }
    int solvetab(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        // n+1 because indx starts from n-1 and index+1 is present in code
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        // index = n is the base  case is 0 which is already 0 in dp vector declaration
        for(int index = n-1; index >=1; index--){
            for(int swapped=1; swapped>=0; swapped--){
                
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swapped){
                    swap(prev1,prev2);
                }

                
                // no swap
                int ans = INT_MAX;
                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = dp[index+1][0];
                }

                // swap
                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans,1+dp[index+1][1]);
                }

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }
    int spaceoptimization(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        
        int swap = 0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;
        

        // index = n is the base  case is 0 which is already 0 in dp vector declaration
        for(int index = n-1; index >=1; index--){
            for(int swapped=1; swapped>=0; swapped--){
                
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swapped){
                    int temp = prev1;
                    prev1 = prev2;
                    prev2 = temp;
                }

                
                // no swap
                int ans = INT_MAX;
                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = noswap;
                }

                // swap
                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans,1+swap);
                }

                if(swapped){
                    currswap = ans;
                }
                else
                    currnoswap = ans;
                    
            }
            swap = currswap;
            noswap = currnoswap;
        }
        return min(swap,noswap);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // insertin -1
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        bool swapped = 0;
        // return solve(nums1,nums2,1,swapped);
        // int n = nums1.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return solvemem(nums1,nums2,1,swapped,dp);
        // return solvetab(nums1,nums2);
        return spaceoptimization(nums1,nums2);
    }
};