#include <bits/stdc++.h>

bool dfs(vector<pair<int,int>>adj[], vector<bool>& visited, int k,int node){

    
    visited[node] = true;
    // reducing value of k till it becomes 0 or greater than given weight
    if(k<=0) return true;

    for(auto nbr : adj[node]){
        int u = nbr.first;
        int w = nbr.second;
        if(!visited[u]){
            
            // if the next weight is more than the reduced value of k
            if(w >= k) return true;

            // decrementing the value of k
            if(dfs(adj,visited,wt,k-w,u)){
                return true;
            }
        }
    }
    // backtracking 
    // putting it inside means we are selecting that loop and we cannot go back
    // only node that is always selected is node 0 therefore it is outside
    visited[node] = false;

    return false;
}
string pathMoreThanK(int n, int m, int k, vector<vector<int>>& ed)
{
    // Write your code here.
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++){
        adj[ed[i][0]].push_back({ed[i][1],ed[i][2]});
        adj[ed[i][1]].push_back({ed[i][0],ed[i][2]});
     }

    vector<bool> visited(n,false);

    // no loop because only one component
    if(dfs(adj,visited,k,0)) return "YES";

    return "NO";
}