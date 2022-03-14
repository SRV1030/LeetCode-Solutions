// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else if(s[i]==')'){
                if(st.empty())st.push(i);
                else{
                    if(s[st.top()]=='(')st.pop();
                    else st.push(i);
                }
            }
        }
        unordered_set<int>t;
        while(!st.empty()){
            t.insert(st.top());
            st.pop();
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')')ans.push_back(s[i]);
            else if(t.find(i)==t.end()) ans.push_back(s[i]);
        }
         return ans;   
    }
};