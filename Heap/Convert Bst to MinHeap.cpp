#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
 
/* Helper function that allocates a new node
   with the given data and NULL left and right
   pointers. */
struct Node* getNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorderTraversal(Node* root, vector<int>& arr)
{
    if (root == NULL)
        return;
 
    // first recur on left subtree
    inorderTraversal(root->left, arr);
 
    // then copy the data of the node
    arr.push_back(root->data);
 
    // now recur for right subtree
    inorderTraversal(root->right, arr);
}
void BSTToMinHeap(Node* root, vector<int> arr, int* i)
{
    if (root == NULL)
        return;
 
    // first copy data at index 'i' of 'arr' to
    // the node
    root->data = arr[++*i];
 
    // then recur on left subtree
    BSTToMinHeap(root->left, arr, i);
 
    // now recur on right subtree
    BSTToMinHeap(root->right, arr, i);
}
void convertToMinHeapUtil(Node* root)
{
    // vector to store the data of all the
    // nodes of the BST
    vector<int> arr;
    int i = -1;
 
    // inorder traversal to populate 'arr'
    inorderTraversal(root, arr);
 
    // BST to MIN HEAP conversion
    BSTToMinHeap(root, arr, &i);
}
void preorderTraversal(Node* root)
{
    if (!root)
        return;
 
    // first print the root's data
    cout << root->data << " ";
 
    // then recur on left subtree
    preorderTraversal(root->left);
 
    // now recur on right subtree
    preorderTraversal(root->right);
}
