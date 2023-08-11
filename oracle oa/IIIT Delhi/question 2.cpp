#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> nums;
    
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        
        nums.push_back(a);
    }
    
    int totalsum = 0;
    
    for(int i=1; i<n; i++){
        totalsum += (nums[i] - nums[i-1])*(nums[i] - nums[i-1]);
    }
    
    int ans = INT_MAX;
    
    // finding middle values of all elements and adding
    // not done for first and last values
    for(int i=1; i<n; i++){
        int mid = ceil(1.0*(nums[i] + nums[i-1])/2);
        ans = min(ans,totalsum + (mid - nums[i-1])*(mid - nums[i-1]) + (nums[i] - mid)*(nums[i] - mid) - (nums[i] - nums[i-1])*(nums[i] - nums[i-1]));
    }
    
    cout<<ans;
    
    return 0;
    
    
    
    
    
}