// https://leetcode.com/problems/longest-chunked-palindrome-decomposition

class Solution {
public:
    int longestDecomposition(string text) {
       int ans=0,l=0,r=text.size()-1;
        stack<int>st;
        queue<int>q;
        while(l<r){
            st.push(text[l++]);
            q.push(text[r--]);
            while(!st.empty() && q.front()==st.top()){
                q.pop();
                st.pop();
            }
            if(st.empty())ans+=l<=r?2:1;
        }
        return ans+1;
    }
};