// https://leetcode.com/problems/basic-calculator-ii

class Solution {
public:
    bool isdig(char x){
        return x>='0' && x<='9';
    }
    int calculate(string s) {
        int n=s.size();
        stack<int>st;
        char op='+';
        for(int i=0;i<n;i++){
            int v=0;
            if(isdig(s[i])){
                while(isdig(s[i])){
                    v=v*10+s[i]-'0';
                    i++;
                }
                if(op=='+')st.push(v);
                else if(op=='-')st.push(-v);
                else if(op=='*'){
                    int x=st.top();
                    st.pop();
                    st.push(x*v);
                }
                else{
                    int x=st.top();
                    st.pop();
                    st.push(x/v);
                }
                i--;
            }
            else if(s[i]==' ')continue;
            else op=s[i];
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};