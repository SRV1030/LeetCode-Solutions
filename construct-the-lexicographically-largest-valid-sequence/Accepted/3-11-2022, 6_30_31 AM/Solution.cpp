// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence

class Solution {
public:
    vector<int>vis,ans;
    bool dfs(int i){
        if(i==ans.size()) return true;
        if(ans[i]) return dfs(i+1);
        for(int j=vis.size()-1;j>0;j--){
            if(vis[j]) continue;
            if(j!=1 && (i+j>=ans.size() || ans[i+j])) continue;
            vis[j]=1;
            ans[i]=j;
            if(j!=1)ans[i+j]=j;
            if(dfs(i+1)) return true;
            vis[j]=0;
            ans[i]=0;
            if(j!=1)ans[i+j]=0;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        ans.assign(2*n-1,0);
        vis.assign(n+1,0);
        dfs(0);
        return ans;
    }
};