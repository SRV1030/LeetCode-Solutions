// https://leetcode.com/problems/task-scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int>mp;
        
        priority_queue<int>pq;
        for(auto i:tasks)mp[i]++;
        if(n<mp.size()) return tasks.size();
        for(auto i:mp)pq.push(i.second);
        int res=0;
        while(!pq.empty()){
            int t=0;
            vector<int>temp;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    t++;
                }
                else break;
            }
            for(auto i:temp)if(i)pq.push(i);
            res+=pq.empty()? t:n+1;
        }
        return res;
    }
};