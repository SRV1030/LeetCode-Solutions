// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting

class Solution {
public:
    int ans=0;
    vector<int>dp;
    void dfs(vector<vector<int>>&adj,vector<int>&vis,int i,int &p){
        vis[i]=1;
        for(auto& j:adj[i]){
            if(!vis[j]){
                p++;
                dfs(adj,vis,j,p);
            }
        }
    }
    int maximumInvitations(vector<int>& fav) {
        int n=fav.size();
        vector<vector<int>>adj(n);
        dp=vector<int>(n+1,-1);        
        for(int i=0;i<n;i++)
            adj[i].push_back(fav[i]);
        for(int i=0;i<n;i++){
            vector<int>vis(n);
            int p=0;
            dfs(adj,vis,i,p);
            ans=max(ans,p+1);
        } 
        return ans; 
    }
};