// https://leetcode.com/problems/decode-string

class Solution {
public:
    bool isNum(char a){
        return a>='0' && a<='9';
    }
    
    string decodeString(string s) {
        stack<char>st;
        string res="";
        for(auto i:s){
            if(i!=']') st.push(i);
            else{
                string ch="";
                while(st.top()!='['){
                    ch+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(ch.begin(),ch.end());
                string dg="";
                while(!st.empty() && isNum(st.top())){
                    dg+=st.top();
                    st.pop();
                }
                reverse(dg.begin(),dg.end());
                string ans="";
                int n=stoi(dg);
                while(n--)ans+=ch;
                for(auto j:ans)st.push(j);
            }
        }
        while(!st.empty()){
             res+=st.top();
             st.pop();
            }
        reverse(res.begin(),res.end());
        return res;
    }
};