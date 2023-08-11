// normal bfs can be used but test cases did not pass so use dijaktras algo
// for better complexity


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        

        int n = grid.size();
        int m = grid[0].size();

        if(n == 1 && grid[0][0] == 0) return 1;
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        // distance array
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = 1;

        queue<pair<int,int>> q;
        q.push({0,0});

        vector<vector<int>> directions = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };

        int count = 1;
        while(!q.empty()){
            
            int size = q.size();

            for(int k=0; k<size; k++){
                auto [i,j] = q.front();
                q.pop();

                grid[i][j] = 1;

                for(auto dir : directions){
                    int newx = i + dir[0];
                    int newy = j + dir[1];

                    if(newx >= 0 && newx < n && newy >=0 && newy < m && grid[newx][newy] == 0){

                        // so that multiple queries are not made
                        if(dist[newx][newy] > dist[i][j] + 1){
                            dist[newx][newy] = dist[i][j] + 1;
                            q.push({newx,newy});
                        }
                    }
                }
            }
        }

        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
    }
};