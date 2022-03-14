// https://leetcode.com/problems/time-needed-to-inform-all-employees

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int lvl=0,mx=0;
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++)
            if(manager[i]!=-1) v[manager[i]].push_back(i);
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto [k,w]=q.front();
                q.pop();
                int dur=informTime[k]+w;
                mx=max(mx,dur);
                for(auto&j:v[k]) q.push({j,dur});
            }
        }
        return mx;       
        
    }
};