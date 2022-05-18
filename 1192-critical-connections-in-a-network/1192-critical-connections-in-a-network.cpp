class Solution {
public:
    vector<int>id,prevLink,vis;
    int time=0;
    vector<vector<int>> g,ans;
    void dfs(int i,int p){
        id[i]=prevLink[i]=time++;
        vis[i]=1;
        for(auto&j:g[i]){
            if(j==p)continue;
            if(!vis[j]){
                dfs(j,i);
                prevLink[i]=min(prevLink[i],prevLink[j]);
                if(id[i]<prevLink[j])ans.push_back({i,j});
            }
            else prevLink[i]=min(prevLink[i],id[j]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        id=vector<int>(n);prevLink=vector<int>(n);vis=vector<int>(n);
        g=vector<vector<int>>(n);
        for(auto&i:connections){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)if(!vis[i])dfs(i,i);
        return ans;
    }
};