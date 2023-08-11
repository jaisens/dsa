class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&s, int n,int count){
        if(count == n/2){
            s.pop();
            return;
        }
        
        int a = s.top();
        s.pop();
        solve(s,n,count+1);
        s.push(a);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        solve(s,sizeOfStack,0);
    }
};