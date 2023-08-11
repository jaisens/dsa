#include<bits/stdc++.h>
using namespace std;

int indexof(int value,vector<int>& nums){
    
    for(int i=0; i<nums.size(); i++){
        if(value == nums[i]){
            return i;
        }
    }
    
    return -1;
}

int main(){
    
    vector<int> nums{3,1,2};
    
    vector<int> temp = nums;
    
    sort(temp.rbegin(),temp.rend());
    
    int ans = 0;
    for(int i=0; i<temp.size(); i++){
        
        if(temp[i] != nums[i]){
            ans++;
            
            swap(nums[i],nums[indexof(nums[i],temp)]);
        }
    }
    
    cout<<ans;
    return 0;
}