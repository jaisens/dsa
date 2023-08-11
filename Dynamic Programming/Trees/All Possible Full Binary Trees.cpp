// we have to find all the full binary tree that can be made with n nodes structures should be non identical and each nodes 
// value will be 0

// observation that even nodes cannot make full binary trees
// so when selecting ith node from n both left and right side should be odd





    unordered_map<int,vector<TreeNode*>> dp;
    vector<TreeNode*> solve(int n){
        
        if(n%2 == 0){  //even nodes
            return {};
        }

        if(n == 1){
            TreeNode* root = new TreeNode(0);
            // returning a vector
            return {root};
        }

        if(dp.find(n) != dp.end()) return dp[n];

        vector<TreeNode*> res;

        // starting from 1 onyl odd values
        for(int i=1; i<n; i+=2){

            // finding left and right full binary tree
            vector<TreeNode*> leftAllFBT = solve(i);
            vector<TreeNode*> rightAllFBT = solve(n-i-1);

            for(auto &l : leftAllFBT){
                for(auto &r : rightAllFBT){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;

                    res.push_back(root);
                }
            }
        }

        return  dp[n] = res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};