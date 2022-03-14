// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>v;
        stack<int>st;
        for(int i=temp.size()-1;i>=0;i--){
            while(!st.empty() && temp[i]>=temp[st.top()])st.pop();
            v.push_back(st.empty()?0:st.top()-i);
            st.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};