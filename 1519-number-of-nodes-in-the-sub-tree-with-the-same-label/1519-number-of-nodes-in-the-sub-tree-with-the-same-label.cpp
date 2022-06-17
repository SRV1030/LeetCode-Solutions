class Solution {
public:
    vector<vector<int>>g;    
    vector<int>ans;
    void dfs(int r,string&l,int f[]){
        if(!ans[r]){
            ans[r]=1;
            for(auto&i:g[r]){
                int f1[26]={};
                dfs(i,l,f1);
                for(int j=0;j<26;++j)f[j]+=f1[j];
            }
            ans[r]=++f[l[r]-'a'];
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        g.resize(n);
        ans.resize(n);
        int f[26]={};
        for(auto&i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        dfs(0,labels,f);
        return ans;
    }
};