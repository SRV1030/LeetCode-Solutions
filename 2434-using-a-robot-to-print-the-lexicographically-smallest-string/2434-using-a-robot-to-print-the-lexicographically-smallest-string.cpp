class Solution {
public:
    int f[26]={};
    char mnc(){
        for(int i=0;i<26;++i)if(f[i]>0)return 'a'+i;
        return 'a';
    }
    string robotWithString(string s) {
        for(auto&i:s)++f[i-'a'];
        stack<char>st;
        string ans;
        for(auto&i:s){
            st.push(i);
            --f[i-'a'];
            while(!st.empty() && st.top()<=mnc()){
                ans+=st.top();
                st.pop();
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};