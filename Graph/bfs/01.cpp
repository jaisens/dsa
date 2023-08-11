class Solution {
public:
    int n,m;
    bool issafe(int i, int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        n = mat.size();
        m = mat[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> ans(n,vector<int>(m,-1));

        // make the 0 elements 0 and push them to queue
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            if(issafe(i+1,j) && ans[i+1][j] == -1){
                q.push({i+1,j});

                // ans[i][j] + 1 because total count is stored in answer why were you adding from original matrix
                ans[i+1][j] = ans[i][j] + 1;
            }
            if(issafe(i-1,j) && ans[i-1][j] == -1){
                q.push({i-1,j});
                ans[i-1][j] = ans[i][j] + 1;
            }
            if(issafe(i,j+1) && ans[i][j+1] == -1){
                q.push({i,j+1});
                ans[i][j+1] = ans[i][j] + 1;
            }
            if(issafe(i,j-1) && ans[i][j-1] == -1){
                q.push({i,j-1});
                ans[i][j-1] = ans[i][j] + 1;
            }
        }

        return ans;
    }
};