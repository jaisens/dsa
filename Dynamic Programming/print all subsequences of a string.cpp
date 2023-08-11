

tc = 2^n
int solve(string s, int i, int n,string output){
    if(i == n){
        cout<<output;
        return;
    }
    else{
        solve(s,i+1,n,output);
        output += s[i];
        solve(s,i+1,n,output);
    }

}