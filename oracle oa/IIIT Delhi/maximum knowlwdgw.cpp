struct fun{     
    bool operator()(vector<int>& v1, vector<int>& v2){ 
                    if(v1[1] == v2[1]){             
                        return v1[0]<v2[0];         
                    }         
                        return v1[1]<v2[1];     
                    }  
};      
class Solution { 
    public:     
    int maxEvents(vector<vector<int>>& events) {
            sort(events.begin(),events.end(),fun());
            int n = events.size();         
            int ans = 0;         
            set<int> s;         
            for(int i=1;i<=events[n-1][1];i++){ // insert till maximum end day from events              
            s.insert(i);         
            }                  
            for(int i=0;i<n;i++){             
                int start = events[i][0], end = events[i][1];             
                auto it = s.lower_bound(start);             
                if(it == s.end() || *(it)>end){                 
                    continue;             
                }             
                else{                 
                    ans++;                 
                    s.erase(it);             
                }         
            }         
            return ans;     
        } 
    };