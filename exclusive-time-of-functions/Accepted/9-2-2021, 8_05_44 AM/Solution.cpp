// https://leetcode.com/problems/exclusive-time-of-functions

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<vector<int>>st;
        vector<int>ans(n);
        for(auto&i :logs){
            i+=':';
            stringstream str(i);
            string id,state,time;
            getline(str,id,':');getline(str,state,':');getline(str,time,':');
            if(state=="start") st.push({stoi(id),stoi(time),0});
            else{
                vector<int>x=st.top();//ct=child time;
                st.pop();
                int interval=stoi(time)-x[1]+1;
                ans[x[0]]+=interval-x[2];
                if(!st.empty())st.top()[2]+=interval;
            }            
        }
        return ans;
    }
};