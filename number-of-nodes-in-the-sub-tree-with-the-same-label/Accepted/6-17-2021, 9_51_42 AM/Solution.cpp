// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

class Solution {
public: 
    vector<vector<int>> g;    
    vector<int>res;
    string s;
        vector<int> dfs(int u,int prev)
    {
        vector<int>curr(26,0);
        curr[s[u]-'a']++;
        for(auto v:g[u])
        {
            if(v==prev)
                continue;
            vector<int> temp=dfs(v,u);
            for(int i=0;i<26;i++)
                curr[i]+=temp[i];
        }
        res[u]=curr[s[u]-'a'];
        return curr;
      return curr;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        g.resize(n);
        s=labels;        
        res.resize(n,0);
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
            // cout<<g[0][1]<<" ";
        }
        dfs(0,-1);              
        return res;
    }
};