class Solution {
public:
    bool match(char a, char b){
        if(a == '('){
            if(b == ')') return true;
            else return false;
        }
        if(a == '{'){
            if(b == '}') return true;
            else return false;
        }
        if(a == '['){
            if(b == ']') return true;
            else return false;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;


        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char top = st.top() ;
                    if((ch == ')' && top == '(') || 
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')){
                        st.pop();
                    }
                    else return false;
                }
                else return false;
            }
        }
        if(st.empty())
            return 1;
        else return 0;
    }
};