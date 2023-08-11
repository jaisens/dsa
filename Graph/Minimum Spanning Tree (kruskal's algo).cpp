#include<algorithm>

//comparator for arranging edges on basis of weight
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];    //a pehle element and b second uske niche wala
}

// only used for intiallizing the parent and rank
//intiallizing parent with itself pointer and rank as 0
void makeset(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

// to find the parent when path compression is not done
int findparent(vector<int> &parent, int node){
    // the topmost node will have the parent as itself so stop after that
    if(parent[node] == node){     //if parent of node is itself then return ans
        return node;
    }
    // recursive for finding parent
    //directly attaching it to source for path compression***
    return parent[node] = findparent(parent, parent[node]);      
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findparent(parent, u);
    v = findparent(parent, v);
    
    // check rank to assign parent
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        // choosing any one of the two
        parent[v] = u;
        // if they are equal
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    //sorting edges on the basis of weights
    // sorting so that larger weights wiil be at last and smaller weights will be used to make tree
    // and when tree is made then skip if the node is already present so larger values are skipped
    sort(edges.begin(), edges.end(), cmp);
      vector<int> rank(n);
      vector<int> parent(n);
      makeset(parent, rank, n);
    
    int minweight = 0;
    
    for(int i=0; i<edges.size(); i++){
        // find parent to check component
        // intially all elements are praent of themselves
        int u = findparent(parent, edges[i][0]);
        int v = findparent(parent, edges[i][1]);
        int wt = edges[i][2];
        
        //nodes are of different  i.e same value of nodes may be present in different graph
        if(u != v){
            minweight+=wt;
            unionset(u,v,parent,rank);
        }
    }
    return minweight;

}