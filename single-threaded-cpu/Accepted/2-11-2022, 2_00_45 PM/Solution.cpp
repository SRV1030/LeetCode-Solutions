// https://leetcode.com/problems/single-threaded-cpu

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++)tasks[i].emplace_back(i);
        sort(tasks.begin(),tasks.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int t=tasks[0][0],p=0;
        vector<int>ans;
        while(p<n){
            while(p<n && tasks[p][0]<=t){
                pq.push({tasks[p][1],tasks[p][2]});
                p++;
            }
            if(pq.empty()){
                t=tasks[p][0];
                continue;                
            }
            pair<int,int>v=pq.top();
            pq.pop();
            t+=v.first;
            ans.emplace_back(v.second);
        }
        while(!pq.empty()){
            pair<int,int>v=pq.top();
            pq.pop();
            ans.emplace_back(v.second);
        }
        return ans;
    }
};