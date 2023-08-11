class Solution{
public:
    void insertatlast(stack<int> &st,int a){
        if(st.empty() == 1){
            st.push(a);
            return;
        }
        
        int x = st.top();
        st.pop();
        insertatlast(st,a);
        st.push(x);
    }
    void Reverse(stack<int> &st){
        if(st.empty() == 1) return;
        
        int a = st.top();
        st.pop();
        Reverse(st);
        
        insertatlast(st,a);
    }
};