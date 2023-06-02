class Solution {
public:    
    vector<vector<int>>g;
    int dfs(bitset<100>&vis,int i){
        if(!vis[i]){
            vis[i]=true;
            for(auto& x:g[i])dfs(vis,x);
        }
        return vis.count();
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int res=0,n=bombs.size();
        g=vector<vector<int>>(n);
        for(int i=0;i<n;i++){
            long long x=bombs[i][0],y=bombs[i][1],r=(long long)bombs[i][2]*bombs[i][2];
            for(int j=0;j<n;j++)
                if((x-bombs[j][0])*(x-bombs[j][0])+(y-bombs[j][1])*(y-bombs[j][1])<=r)  g[i].push_back(j); 
        }
        for(int i=0;i<n && res<n;i++){
            res=max(res,dfs(bitset<100>()={},i));
        }
        return res;
    }
};