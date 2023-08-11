class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
     
        int m = grid.size();
        int n = grid[0].size();
        
        int answer = 0;
        
        //starting from last row
        int i = m-1;
        //and first coloumn
        int j = 0;
        
        // counting each row negatives 

        while(i>=0 && i<m && j>=0 && j<n){
            
            if(grid[i][j] < 0){
                answer += n - j;
                i--;
            }
            else{
                //j only increase because if positive is found then the previous row element will surely be positive
                //j increases only beacuse once negative is found it next's previous row element will be negative
                j++;
            }
        }
        return answer;
    }
};