// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
        
        priority_queue<long long, vector<long long>, greater<long long> > q;
        
        //pushing data to min heap
        for(int i=0; i<n; i++)
            q.push(arr[i]);

        //dont be confused with cost and sum make diagram for better understanding    
        long long cost = 0;
        
        while(q.size() > 1){
            
            long long a = q.top();
            q.pop();
            
            long long b = q.top();
            q.pop();
            
            long long sum = a + b;
            
            q.push(sum);
            
            cost += sum;   //do not put space between + and =
            
        }
        
        return cost;
    }
};
