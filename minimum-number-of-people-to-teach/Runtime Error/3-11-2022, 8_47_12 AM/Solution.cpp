// https://leetcode.com/problems/minimum-number-of-people-to-teach

class Solution {
public:
    int dp[501][501]={};
    vector<set<int>>l;
    bool check(int i,int j){
        if(dp[i][j]!=0) return dp[i][j]==1;
        for(auto&v:l[i]){
            if(l[j].count(v)){
                dp[i][j]=dp[j][i]=1;
                return true;
            }
        }
        dp[i][j]=dp[j][i]=-1;
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        for(auto&i:languages)l.push_back(set<int>(i.begin(),i.end()));
        int res=languages.size();
        for(int i=1;i<=n;i++){
            int c=0;
            vector<int>vis(n+1);
            for(auto &fr:friendships){
                int u=fr[0]-1,v=fr[1]-1;
                if(check(u,v)) continue;
                if(!vis[u] && !l[u].count(i)){
                    c++;
                    vis[u]=1;
                }
                if(!vis[v] && !l[v].count(i)){
                    c++;
                    vis[v]=1;
                }
            }
            res=min(res,c);
        }
        return res;
    }
};