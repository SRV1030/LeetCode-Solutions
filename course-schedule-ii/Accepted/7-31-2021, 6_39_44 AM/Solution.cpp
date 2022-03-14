// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    bool dfs(vector<vector<int>> grid,vector<bool> &vis,vector<bool> &visP,int i){
        vis[i]=true;
        visP[i]=true;
        for(auto j:grid[i]){
            if(!vis[j])
                if(dfs(grid,vis,visP,j)) return true;
            if(visP[j]) return true;
        }
        visP[i]=false;
        return false;        
    }
    bool detectCycle(vector<vector<int>> grid, int V){
        vector<bool> vis(V,false),visP(V,false);
        for(int i=0;i<V;i++)
            if(!vis[i])
                if(dfs(grid,vis,visP,i)) return true;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(auto i:prerequisites) g[i[1]].push_back(i[0]);
        vector<int> ans;
        // if(detectCycle(g,numCourses)) return ans;
        queue<int> q;
        vector<int>ind(numCourses);
        for(auto i:g)
            for(auto j:i) ind[j]++;
        for(int i=0;i<numCourses;i++)
            if(!ind[i]) q.push(i);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int x=q.front();
                q.pop();
                ans.push_back(x);
                for(auto i:g[x]){
                    ind[i]--;
                    if(ind[i]==0) q.push(i);
                }
                    
            }
        }
        return ans.size()==numCourses?ans:vector<int>();
    }
};