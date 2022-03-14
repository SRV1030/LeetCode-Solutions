// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int mxv=0,c=0;
        stack<char>st;
        for(auto&i:s){
            if(i=='(') st.push(i);
            else{
                if(st.empty()){
                    if(c>mxv)mxv=c;
                    c=0;
                }else{
                   c++;
                    st.pop();
                }
            }
        }
        if(c>mxv)mxv=c;
        return 2*mxv;
    }
};