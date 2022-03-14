// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(auto&i:num){
            while(!st.empty() && k>0 && st.top()>i){
                st.pop();
                k--;
            }
            if(st.empty() && i=='0')continue;
            st.push(i);
        }
        while(!st.empty() && k--) st.pop();
        string res="";
        while(!st.empty()){
            res.insert(res.begin(),st.top());
            st.pop();
        }
        return res==""?"0":res;
    }
};