class Solution {
public:

    // same as inorder traversal so counting the ith element using inorder
    // ***use &k because this will take the orignal value in each loop

    int kthSmallest(TreeNode* root, int &k) {
        if(root == NULL) return -1;

        int left = kthSmallest(root->left,k);
        // if answer is found then return
        if(left != -1) return left;

        k--;
        if(k==0) return root->val;

        int right = kthSmallest(root->right,k);
        if(right != -1) return right;

        return -1;
    }
};