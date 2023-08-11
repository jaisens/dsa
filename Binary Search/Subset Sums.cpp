#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> nums,int start, int end,vector<int>& v){
    int s = 0;
    int n = end - start + 1;
    
    // for finding subsets
for(int i=0; i<(1<<n); i++){
        s = 0;
        int j = start;
        int x = i;

        while(x){
            int l = x&1;
            if(l) s+= nums[j];
            j++;
            x = x>>1;
        }
        
        v.push_back(s);
    }
}
int main(){
    int n,a,b;
    
    cin>>n>>a>>b;
    
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    
    vector<int> v1,v2;
    
    // make two halves so that time complexity of both the haves become less and add subset sums at the end
    solve(nums,0,(n/2)-1,v1);
    solve(nums,n/2,n-1,v2);
    
    // so that we can apply binary search
    sort(v2.begin(),v2.end());
    
    int count = 0;
    
    // find the sum in range
    for(int i=0; i<v1.size(); i++){
        int low = lower_bound(v2.begin(),v2.end(),a-v1[i])-v2.begin();
        int high = upper_bound(v2.begin(),v2.end(),b-v1[i])-v2.begin();
        
        count += high - low;
    }
    
    cout<<count;
    
    return 0;
    
}