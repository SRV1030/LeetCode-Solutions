// https://leetcode.com/problems/time-needed-to-inform-all-employees

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int lvl=0,mit=0;
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++)
            if(manager[i]!=-1) v[manager[i]].push_back(i);
        queue<int>q;
        q.push(headID);
        while(!q.empty()){
            int n=q.size(),mx=0;
            while(n--){
                int i=q.front();
                q.pop();
                mx=max(mx,informTime[i]);
                for(auto&j:v[i]) q.push(j);
            }
            mit+=mx;
        }
        return mit;       
        
    }
};