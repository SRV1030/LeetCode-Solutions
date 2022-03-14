// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        string ans="";
        for(auto i:s){
            if(st.empty() || st.top().first!=i)st.push({i,1});
            else if(st.top().first==i)st.top().second++;
            if(st.top().second%k==0)st.pop();
            else if(st.top().second>k)st.top().second-=k;
        }
        while(!st.empty()){
            while(st.top().second--)ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};