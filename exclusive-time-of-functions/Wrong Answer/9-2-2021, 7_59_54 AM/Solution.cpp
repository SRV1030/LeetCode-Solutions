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
                int c=stoi(time)-x[1]+1-x[2];
                ans[x[0]]+=c;
                if(!st.empty())st.top()[2]+=c;
            }            
        }
        return ans;
    }
};