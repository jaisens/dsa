#include<unordered_map>
#include<list>
#include<stack>
void dfstopo(unordered_map<int, list<int> > &adj, vector<int> &visited , stack<int> &s, int node){
    visited[node] = 1;
    
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            dfstopo(adj, visited, s, neighbour);
        }
    }
    //only elements which are not visited are sent as node in recursive call hence only non visited elements will be 
    //pushed in stack
    //last element will be put first in stack
    s.push(node);
    
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    unordered_map<int, list<int> > adj; ///in this also vector can be used for better space optimisaitoin
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        
    }
    
    //unordered_map<int, bool> visited; can be used but using vector is more space optimised
    vector<int> visited(v);
    stack<int> s;
    
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfstopo(adj, visited, s, i);  
        }
    }
    
    vector<int> ans;
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}