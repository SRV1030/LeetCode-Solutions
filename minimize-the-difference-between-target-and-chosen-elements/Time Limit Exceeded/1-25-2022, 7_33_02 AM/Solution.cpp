// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements

class Solution {
public:
    int mn=INT_MAX;
    bool dp[71][5000];
    void dfs(vector<vector<int>>& mat,int i,int &target,int cur){
        if(cur-mn>=target || i>mat.size() || (dp[i][cur])) return;
        if(i==mat.size()){
            int v=abs(target-cur);
            if(v<mn)mn=v;
        }
        else{            
            for(int j=0;j<mat[0].size();j++)
                dfs(mat,i+1,target,cur+mat[i][j]);            
        }
        dp[i][cur]=true;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp,false,sizeof(dp));
        dfs(mat,0,target,0);
        return mn;
    }
};