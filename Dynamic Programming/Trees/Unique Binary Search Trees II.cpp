// similar to all possible full binary tree question
// go from 1 to n and make binary tree of left and right



    // unordered_map was not working
    map<pair<int,int>,vector<TreeNode*>> mp;
    vector<TreeNode*> solve(int start, int end){
        if(start > end){
            return {NULL};
        }

        if(start == end){
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        if(mp.find({start,end}) != mp.end()) return mp[{start,end}];

        vector<TreeNode*> res;

        // start and end
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left_bsts = solve(start, i-1);
            vector<TreeNode*> right_bsts = solve(i+1, end);

            for(auto &l : left_bsts){
                for(auto &r : right_bsts){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        return mp[{start,end}] = res;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        //start from 1 because we need to assign values to nodes
        return solve(1,n);
    }
};