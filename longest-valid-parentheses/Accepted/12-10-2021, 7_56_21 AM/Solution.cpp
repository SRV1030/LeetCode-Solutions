// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int mxv=0,c=0;
        stack<int>st;
        st.push(-1);
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty())st.push(i);
                else mxv=max(mxv,i-st.top());
            }
        }
        return mxv;
    }
};