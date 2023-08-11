//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int> s;
        s.push(-1);   //push -1 for last element and if no smaller element is found
        //int n = arr.size();
        vector<int> ans(n);
        
        //traversing from right to left so that the smaller element can be stored for prev elements
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];        //intiallizing variable for better use
            while(s.top() >= curr){     //popping elements till smaller element is found
                s.pop();
            }
            ans[i] = s.top();   //storing answer
            s.push(curr);      //pushing the current element so that it can also be checked for smaller for the next element
        }
        return ans;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends