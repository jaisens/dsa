// do dfs for one island then mark them visited or put them in viisted set
// then do bfs because it will find the minimum distance island in shortest steps henve shortest flipss
// fo bfs for all not visited elements if it is 1 then return count or level


    int n,m;
    bool isSafe(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }

    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& grid, int i,int j, set<pair<int,int>> &visited){
        // put not safe elements
        // only not visited elements which have value 1
        if(!isSafe(i,j) || grid[i][j] == 0 || visited.find({i,j}) != visited.end()){
            return;
        }

        visited.insert({i,j});

        for(auto dir : directions){
            int new_x = i + dir[0];
            int new_y = j + dir[1];

            dfs(grid,new_x,new_y,visited);
        } 
    }
    int bfs(vector<vector<int>>& grid, set<pair<int, int>>& visitedCell) {
        queue<pair<int, int>> que;
        
        for(auto &it : visitedCell) {
            
            que.push({it});
            
        }
        
        int level = 0;
        
        while(!que.empty()) {
            int L = que.size();
            
            while(L--) {
                pair<int, int> P = que.front();
                que.pop();
                
                for(auto &dir : directions) {
                    int i_ = P.first + dir[0];
                    int j_ = P.second + dir[1];

                    // not viisted cells are put which are 0 and final ans will be 1
                    if(isSafe(i_, j_) && visitedCell.find({i_, j_}) == visitedCell.end()) {
                        if(grid[i_][j_] == 1) //found another island
                            return level;
                        
                        visitedCell.insert({i_, j_});
                        que.push({i_, j_});
                    }
                }
                
            }
            level++;
        }
        
        return level;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();

        set<pair<int,int>> visited;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == 1){
                    dfs(grid,i,j,visited);
                    return bfs(grid,visited);
                }

            }
        }

        return -1;

    }
};