class Solution {
public:
    // intutive method
    // mapping and doing it like word break
    int solve(string &s,unordered_map<string,char> &mp, int index,vector<int> &dp){

        if(index >= s.size()) return 1;

        if(dp[index] != -1) return dp[index];

        int count = 0;
        string temp = "";
        for(int i=index; i<s.size(); i++){
            temp += s[i];
            if(mp.find(temp) != mp.end()){
                count += solve(s,mp,i+1,dp);
            }
        }

        return dp[index] = count;
    }


    // optimal method
    int dp[105];
    int solve2(string &s, int index){
        // reached last index 
        if(index == s.size()) return 1;

        // this is present because index+2 is used which can cause errors 
        if(index > s.size()) return 0;

        // 0 cannot be present in front of a digit hence returning 0
        if(s[index] == '0') return 0;

        if(dp[index] != -1) return dp[index];

        int ans = 0;
        if(s[index] == '1'){
            ans += solve2(s,index+1) + solve2(s,index+2);
        }
        else if(s[index] == '2' && index+1 < s.size() && s[index+1] >= '0' && s[index+1] <= '6'){
            // 20 - 26 letters are mapped
            ans += solve2(s,index+1) + solve2(s,index+2);
        }
        else{
            ans += solve2(s,index+1);
        }

        return dp[index] = ans;

    }

    int solvetab(string &s, unordered_map<string,char> &mp ){
        
        int n = s.size();
        vector<int> dp(n+1,0);

        dp[n] = 1;

        for(int index=n-1; index>=0; index--){

            int count = 0;
            string temp = "";
            for(int i=index; i<s.size(); i++){
                temp += s[i];
                if(mp.find(temp) != mp.end()){
                    count += dp[i+1];
                }
            }

            dp[index] = count;
        }

        return dp[0];

    }
    int numDecodings(string s) {

        // unordered_map<string,char> mp;
        // char ch = 'A';

        // for(int i=1; i<=26; i++){
        //     mp[to_string(i)] = ch;
        //     ch++;
        // }

        // // vector<int> dp(s.size(),-1);
        // // return solve(s,mp,0,dp);

        // return solvetab(s,mp);

        memset(dp,-1,sizeof(dp));

        return solve2(s,0);
    }
};