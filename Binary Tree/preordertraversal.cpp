// morris traversal
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;

        TreeNode* curr = root;

        while(curr){
            // 1st case
            if(!curr->left){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = curr;
                    // changed here
                    inorder.push_back(curr->val);
                    curr = curr->left;
                }

                else{
                    prev->right = NULL;
                    
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }