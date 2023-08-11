class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows= matrix.size();
        int col = matrix[0].size() - 1;
        int row = 0;
        
        //binary tree type implementation
        //starting from top right corner and going left small elements are found and by going down value increases
        while(row < rows && col > -1){
            int a = matrix[row][col];
            if(a == target) return true;
            else if(a > target){
                col--;
            }
            else
                row++;
        }
        return false;
    }
};