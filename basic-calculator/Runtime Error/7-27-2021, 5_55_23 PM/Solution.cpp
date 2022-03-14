// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    int calculate(string s) {
        int sign=1,v=0,res=0;
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])) v=v*10+s[i]-'0';
            else if(s[i]=='+'){
                res+=sign*v;
                v=0;
                sign=1;
            }   
            else if(s[i]=='-'){
                res+=sign*v;
                v=0;
                sign=-1;
            } 
            else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            } 
            else if(s[i]==')'){
                res+=sign*v;
                res*=st.top();
                st.pop();
                res+=st.top();
                st.pop();
                v=0;
                sign=1;
            }             
        }
        if(v>0) res+=sign*v;
        return res;
    }
};