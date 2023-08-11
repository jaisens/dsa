class Solution {
public:
    vector<int> nextsmaller(vector<int> heights, int n){
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()]>=curr){      //heights[s.top()] is used because vector of ans stores
                                                                //index of next smaller elements
                s.pop();
            }  
            ans[i] = s.top();  // stores 
            s.push(i);     //stores index so that area can be calculared
        }
        return ans;
    }
    vector<int> prevsmaller(vector<int> heights, int n){
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){     //from 0 to n for prevsmaller elements
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()]>=curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);       //stores index 
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
      
        int n = heights.size();
        vector<int> prev(n);
        vector<int> next(n);
        
        prev = prevsmaller(heights,n);     //gettig the prevsmaller vectior
        next = nextsmaller(heights,n);
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            int l = heights[i];
            if(next[i] == -1){      //if alll the elements are same then next[i] of will be negative so assign it n
                next[i] = n;
            }
            int b = next[i]-prev[i]-1;   //then calculate the breadth
            int area = l*b;
            ans = max(area,ans);
        }
        return ans;
    }
};