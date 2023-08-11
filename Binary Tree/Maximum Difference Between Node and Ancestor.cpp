//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
//this problem is about trees but they are no arranged in increasing or decreasing manner
//we have considered individual paths from root node to leaf and in each path we have found out max
// and min elements.


class Solution {
public:
    int findmaxdiff(TreeNode* root, int maxval, int minval){
        //base case
        if(root == NULL){
            //we have reached the end of the path we can return the difference of min and max elements
            return abs(maxval - minval);
        }

        //update max and min
        //as we traverse we check value of each node and check it is min or max element
        maxval = max(root->val,maxval);
        minval = min(root->val,minval);

        //traversal
    
        int left = findmaxdiff(root->left,maxval,minval);
        int right = findmaxdiff(root->right,maxval,minval);

        return max(left,right);
    }

    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return 0;
        return findmaxdiff(root,root->val,root->val);
    }
};