class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
        vector<vector<int>> ans,g(8,vector<int>(8));
        for(auto&i:queens)g[i[0]][i[1]]=1;
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        for(int i=1;i<=8;++i){
            vector<vector<int>>t;
            for(auto&d:dir){
                int x=k[0]+d[0]*i,y=k[1]+d[1]*i;
                if(min(x,y)>=0 && max(x,y)<8 && g[x][y])ans.push_back({x,y});
                else t.push_back({d[0],d[1]});
            }
            dir=t;
        }
        return ans;
    }
};