// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>vis(26),f(26);
        stack<char>st;
        for(auto& i:s)f[i-'a']++;
        for(auto& i:s){
            if(!vis[i-'a']){
                while(!st.empty() && i<st.top() && f[st.top()-'a']>1){
                    f[st.top()-'a']--;
                    vis[st.top()-'a']=0;
                    st.pop();
                }
                vis[i-'a']=1;
                st.push(i);
            }
            else f[i-'a']--;
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
