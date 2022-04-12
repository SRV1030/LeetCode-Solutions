class Solution {
public:
    int maxDepth(string s) {
        int mx=0,c=0;
        stack<char>st;
        for(auto&i:s){
            if(i!='(' && i!=')') continue;
            if(i=='(') st.push('(');
            else {
                mx=max(mx,(int)st.size());
                st.pop();
            }
        }
        return mx;
    }
};