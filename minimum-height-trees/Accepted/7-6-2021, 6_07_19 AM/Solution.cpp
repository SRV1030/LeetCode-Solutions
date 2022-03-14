// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<unordered_set<int>>adj(n);
        for(auto i:edges){
            adj[i[0]].insert(i[1]);
            adj[i[1]].insert(i[0]);
        }
        queue<int>q;
        for(int i=0;i<adj.size();i++)
            if(adj[i].size()==1)q.push(i);
        while(n>2){
            int l=q.size();
            n-=l;            
            for(int i=0;i<l;i++){
                int node=q.front();
                q.pop();
                for(auto i:adj[node]){
                    adj[i].erase(node);
                    if(adj[i].size()==1)q.push(i);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};