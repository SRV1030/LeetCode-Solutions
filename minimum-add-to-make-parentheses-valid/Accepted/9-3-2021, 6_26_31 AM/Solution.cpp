// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        stack<char>st;
        for(auto& i:s){
            if(i=='(')st.push(i);
            else{
                if(st.empty())ans++;
                else st.pop();
            }
        }
        return ans+st.size();
        
    }
};