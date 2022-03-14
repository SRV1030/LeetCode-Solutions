// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>st;
        int n=t.size();
        vector<int> ans;
        for(int i=t.size()-1;i>=0;i--){
            while(!st.empty() && t[i]>=t[st.top()]) st.pop();
            int a= st.empty()?0:st.top()-i;
            ans.push_back(a);            
            st.push(i);  
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};