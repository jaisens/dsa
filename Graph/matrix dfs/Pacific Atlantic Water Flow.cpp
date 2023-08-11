// think in reverse order find all the edges and traverse the indices if greater than them marrk it as 1
// and do dfs 
// do it for both the oceans and
// whereever both ocean matrix are 1 that is the answ

// TC O(n*m) SC = O(n*m)


    void dfs(vector<vector<int>>& h, int i,int j,int prev,vector<vector<int>>& ocean){
        if(i<0 || j<0 || i >= h.size() || j >= h[0].size()){
            return;
        }

        if(ocean[i][j] == 1) return;

        if(h[i][j] < prev) return;

        ocean[i][j] = 1;

        dfs(h,i+1,j,h[i][j],ocean);
        dfs(h,i-1,j,h[i][j],ocean);
        dfs(h,i,j+1,h[i][j],ocean);
        dfs(h,i,j-1,h[i][j],ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));

        for(int j=0; j<m; j++){
            dfs(heights, 0, j, INT_MIN, pacific);
            dfs(heights, n-1, j, INT_MIN, atlantic);
        }

        for(int i=0; i<n; i++){
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, m-1, INT_MIN, atlantic);
        }

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    vector<int> temp(2);
                    temp[0] = i;
                    temp[1] = j;
                    ans.push_back(temp);
                }

            }
        }


        return ans;


    }
};