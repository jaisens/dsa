// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void heapify(vector<int> &arr, int n, int idx)
    {
        // Find largest of node and its children
        if (idx >= n)
            return;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        int max;
        if (l < n && arr[l] > arr[idx])
            max = l;
        else
            max = idx;
        if (r < n && arr[r] > arr[max])
            max = r;
     
        // Put maximum value at root and
        // recur for the child with the
        // maximum value
        if (max != idx) {
            swap(arr[max], arr[idx]);
            heapify(arr, n, max);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //step 1
        vector<int> ans;
        for(auto i:a)
            ans.push_back(i);
        
        for(auto j:b)
            ans.push_back(j);
        
        
        //step 2
        int size = n+m;
        for(int i=(size/2) - 1; i>=0; i--){   //used heapify to make the maxheap 
                                              // = and not equal to should be carefully used when index of heaps change
            heapify(ans,size,i);
        }
        
        
            
        return ans;
    }
};
