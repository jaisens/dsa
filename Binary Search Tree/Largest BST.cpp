class Solution{
    public:
    class info{
        public:
        int maxi;
        int mini;
        bool isbst;
        int size;
    };
    
    info findbstsize(Node *root, int & ans){
        if(root == NULL){
            // to return values of type class put it in curly brackets
            return {INT_MIN,INT_MAX,true,0};
        }
        
        //left and right traversals
        info left = findbstsize(root->left,ans);
        info right = findbstsize(root->right,ans);
        
        //represents the N(inoder N root) in a recursive loop 
        //used because 4 values are needed to be stored and checked and as others are class it is also stored in class
        //else it will become cubersome

        // currnode stores all the values of the rootnode which we are on 
        info currnode;
        
        currnode.size = left.size + right.size + 1;   // +1 very important increases the size of valid bst
        currnode.maxi = max(root->data,right.maxi);   //obvious
        currnode.mini = min(root->data,left.mini);
        
        //left ans right subtree should be valid and data should be smaller and bigger respectively
        if(left.isbst && right.isbst && (root->data > left.maxi && root->data < right.mini)){
            currnode.isbst = true;
        }
        else{
            currnode.isbst = false;
        }
        
        //if root node bst is valid store the ans
        if(currnode.isbst){
            ans = max(ans,currnode.size);
        }
        //returning so that recursive loop can continue i guess or else no use case
        //return value into left and right info class elements
        return currnode;
    }
    int largestBst(Node *root)
    {
        int ans=0;  //passed by refernce
    	info temp = findbstsize(root,ans);   //do not return temp.size 
    	return ans;
    }
};

