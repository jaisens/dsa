// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
  //to count number of nodes
    int countnodes(struct Node* tree){
        if(tree == NULL) return 0;
        
        return 1 + countnodes(tree->left) + countnodes(tree->right);
    }
    
    bool maxorder(struct Node* root){
        // 3 cases present in tree to check if the root element is bigger 
        // both left and right are null
        // right is null - left check nhi karna hai
        // both are not null
        if(!root->left && !root->right) return 1;
        
        else if(root->right == NULL){
            return root->data > root->left->data;
        }
        
        else{
            bool left = maxorder(root->left);
            bool right = maxorder(root->right);
            
            // also check if root is greater that left and right
            return left&&right&&(root->data > root->left->data)&&(root->data > root->right->data);
        }

    }
    
    bool isCBT(struct Node* root, int size, int i){
        
        if(root == NULL) return true;
        
        // if i>=size then some nodes were NULL and after that nodes are added which is not possible
        //  = because 0 base indexing
        
        if( i>=size ) return false;
        
        
        bool left = isCBT(root->left,size,2*i+1);
        bool right = isCBT(root->right,size,2*i+2);
        
        return left&&right;

    }
    bool isHeap(struct Node* tree) {
        // code here
        int size = countnodes(tree);
        int i = 0;
        
        //check cbt before because !left and right case is not handled in maxorder
        if(isCBT(tree,size,i)&&maxorder(tree))
            return true;
        
        return false;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}  // } Driver Code Ends