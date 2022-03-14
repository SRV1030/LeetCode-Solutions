// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string t="";
        int i=0,j=s.size()-1;
        while(s[i]==' ') i++;
        while(s[j]==' ') j--;
        if(i>=j) return s;
        for(;i<=j;i++){
            if(s[i]==' '){
                while(s[i]==' ') i++;
                i--;
                st.push(t);
                t="";
            }
            else t+=s[i];
        }
        if(t.length()>0) st.push(t);
        t="";
        while(!st.empty()){
            t+=st.top();
            st.pop();
            if(st.empty()) return t;
            t+=" ";
        }
         return t;
    }
};