#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // isme dono test case ke algo match hi nhi kar rhe
    vector<int> rec{3,1,4,2};
    int n = rec.size();
    
    
    long long second = 4;
    
    int i=0;
    
    while(second != 0){
        
        if(i == n-1){
            second = second - 1;
            if(second == 0) return 1;
            else second = second - 1;
        }
        else{
            if(rec[i] != 1) second--;
        }
        
        i = (i+1)%(n);
        
    }
    
    cout<<rec[i-1];
    
    return 0;
    
    
    
}