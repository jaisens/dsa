// return dfs(...) cannot be used in place of up down lefrf..  because then whenever true is returned it will not go further 
// and remaining cells will not be visited and later cause error
// so using up down ... because eevery connected cell will be visited and we will be able to evaluate whether it is true or not
// ans add count


    bool dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j){
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || j<0) return false;

        // two conditions
        if(grid[i][j] == 1 || visited[i][j] == 1){
            return true;
        }

        // here we can also make the cell 1 
        visited[i][j] = 1;

        bool up = dfs(grid,visited,i-1,j);
        bool down = dfs(grid,visited,i+1,j);
        bool left = dfs(grid,visited,i,j-1);
        bool right = dfs(grid,visited,i,j+1);

        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0 && !visited[i][j]){
                    if(dfs(grid,visited,i,j)){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};