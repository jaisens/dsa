// LIS question with extra count array to store maximum count at a particular index

    // TC = O(n^2) SC = O(n)
    
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        // stores length of the lis including that index
        vector<int> t(n,1);
        // stores number of lis till that index
        vector<int> count(n,1);


        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){

                if(nums[j] < nums[i]){
                    // if same element already present
                    if(t[j] + 1 == t[i]){
                        count[i] += count[j];
                    }
                    // if bigger element is found then count becomes count[j]
                    else if(t[j] + 1 > t[i]){
                        t[i] = t[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }

        int maxval = *max_element(t.begin(),t.end());

        int ans = 0;
        for(int i=0; i<n; i++){
            // wherever index has length equal to maxval add the count to answer
            if(t[i] == maxval){
                ans += count[i];
            }
        }

        return ans;
    }
};