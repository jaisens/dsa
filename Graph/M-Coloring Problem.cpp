bool possible(bool graph[101][101],vector<int>& color, int n,int col,int index){
        
        for(int i=0; i<n; i++){
            if(graph[index][i] == 1){
                if(color[i] == col){
                    return false;
                }
            }
        }
        return true;
    }
    bool rec(bool graph[101][101], int n, int m,int index,vector<int>& color){
        
        if(index >=n) return true;
        
        for(int i=1; i<=m; i++){
            
            if(possible(graph,color,n,i,index)){
                color[index] = i;
                // here backtracking is inside if loop because the increment is done using recursion
                // and in path more than distance k the increment is done using the for loop
                if(rec(graph,n,m,index+1,color)){
                    return true;
                }
                else {
                    color[index] = 0;
                }
            }
        }
        
        return false;
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n,0);
        return rec(graph,n,m,0,color);
    }

    // *** better
    bool ispossible(bool graph[101][101],int node, int col, int n, vector<int>&color){
        
        for(int i=0; i<n; i++){
            if(i!=node && graph[node][i] == 1 && color[i]==col)
                return false;
        }
        
        return true;
    }
    bool solve(bool graph[101][101],int node, int m, int n, vector<int>&color){
        
        if(node == n) return true;
        
        for(int i=1; i<=m; i++){
            
            if(ispossible(graph,node,i,n,color)){
                color[node] = i;
                if(solve(graph,node+1,m,n,color)){
                    return true;
                }
                color[node] = 0;
            }
        }
        
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        vector<int> color(n,0);
        return solve(graph,0,m,n,color);
    }

    // *** better end


    //second method
    // we can find maximum number of nodes are connected to a each node + 1 and that will be maximum number of
    // colours required to color the nodes
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        unordered_map<int,vector<int>> adj;
        
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                if(graph[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int maxi = -1;
        for(int i=0; i<adj.size(); i++){
            int len = adj[i].size();
            maxi = max(maxi,(len+1));
        }
        
        if(m >= maxi) return 1;
        return 0;
    }