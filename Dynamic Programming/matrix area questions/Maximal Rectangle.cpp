class Solution {
public:
vector<int> nextsmaller(vector<int> heights, int n){
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()]>=curr){    
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
            if(next[i] == -1){      
                next[i] = n;
            }
            int b = next[i]-prev[i]-1;   //then calculate the breadth
            int area = l*b;
            ans = max(area,ans);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxi = 0;
        vector<int> histogram(matrix[0].size(),0);

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<histogram.size(); j++){
                if(matrix[i][j] == '1')
                    histogram[j]++;
                else{
                    histogram[j] = 0;
                }
            }
            maxi = max(maxi,largestRectangleArea(histogram));
        }
        return maxi;
    }
};