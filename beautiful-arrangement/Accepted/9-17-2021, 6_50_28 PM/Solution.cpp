// https://leetcode.com/problems/beautiful-arrangement

class Solution {
public:
int res=0;
    vector<int> vis;
    void dfs(int n,int ind){
        if(ind>n)res++;
        for(int i=1;i<=n;i++){
            if(!vis[i] && (i%ind==0 || ind%i==0)){
                vis[i]=1;
                dfs(n,ind+1);
                vis[i]=0;
            }
        }
    }
    int countArrangement(int n) {
        if(n<=2) return n;
        vis=vector<int>(n+1);
        dfs(n,1);
        return res;
    }
};