class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto&i:s){
            bool f=0;
            while(!st.empty() && i==st.top()) {
                st.pop();
                f=1;
            }
            if(!f) st.push(i);
        }
        string ans;
        while(!st.empty()){
             ans+=st.top();
             st.pop();
         }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};