#include<bits/stdc++.h>
using namespace std;

// https://www.thejoboverflow.com/p/p1300/ question-1

void frequencyofmaxvalue(vector<int> &nums, vector<int>& q){
    
    
    // O(n) tc o(n)
    unordered_map<int,int> mp;
    
    vector<int> ans;
    unordered_map<int,int> countatindex;
    
    for(int i=nums.size()-1; i>=0; i--){
        mp[nums[i]]++;
        
        countatindex[i] = mp[nums[i]];
    }
    
    for(int i=0; i<q.size(); i++){
        ans.push_back(countatindex[q[i]-1]);
    }
    
    for(auto i : ans) cout<<i;
    
    
    // o(n^2) me bhi bana skate q se index leke bar bar loop chalake
}

int main(){
    int n;
    cin>>n;
    
    vector<int> nums;
    vector<int> q;
    
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    
    // can also be greater than n
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        q.push_back(a);
    }
    
    
    frequencyofmaxvalue(nums,q);
    
    return 0;
    
}