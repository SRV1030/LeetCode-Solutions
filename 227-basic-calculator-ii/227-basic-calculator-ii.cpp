class Solution {
public:
    bool isdig(char x){
        return x>='0' && x<='9';
    }
    long long int calculate(string s) {
        int n=s.size();
        stack<long long int>st;
        char op='+';
        for(int i=0;i<n;i++){
            long long int v=0;
            if(isdig(s[i])){
                while(isdig(s[i])){
                    v=v*10+s[i]-'0';
                    i++;
                }
                if(op=='+')st.push(v);
                else if(op=='-')st.push(-v);
                else if(op=='*') st.top()*=v;
                else st.top()/=v;
                i--;
            }
            else if(s[i]==' ')continue;
            else op=s[i];
        }
        long long int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};