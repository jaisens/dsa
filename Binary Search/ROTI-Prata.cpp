#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& rank,int req,int mid){
    
    int n = rank.size();
    
    int pratacount =  0;
    int time = 0;
    
    for(int i=0; i<n; i++){
        time = rank[i];
        int j = 2;
        while(time <= mid){
            pratacount++;
            time += rank[i]*j;
            j++;
        }
        
        if(pratacount>=req) return 1;
    }
    // cout<<pratacount<<endl;
    
    return 0;
}
int main(){
    int t;
    cin>>t;
    
    while(t--){
        int p;
        cin>>p;
        
        int l;
        cin>>l;
        
        vector<int> rank(l);
        
        for(int i=0; i<l; i++){
            cin>>rank[i];
        }
        
        // we can take this bounds when confused about them
        int lb = 0;
        int ub = 1e8;
        int ans = 0;
        
        while(lb<=ub){
            int mid = (lb + ub)/2;
            
            if(solve(rank,p,mid)){
                ans = mid;
                ub = mid -1;
            }
            else{
                lb = mid + 1;
            }
        }
        
        cout<<ans<<endl;

    }
    
    return 0;
}