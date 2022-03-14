// https://leetcode.com/problems/find-all-groups-of-farmland

class Solution {
public:
    void dfs(vector<vector<int>>& land,int i,int j,int &r,int &c){
        if(i<0 || i>=land.size() || j<0 || j>=land[0].size() || land[i][j]!=1) return;
        if(i>r)r=i;
        if(j>c)c=j;
        land[i][j]=-1;
        dfs(land,i+1,j,r,c);
        dfs(land,i,j+1,r,c);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]==1){                    
                    int r=0,c=0;
                    dfs(land,i,j,r,c);
                    ans.push_back({i,j,r,c});
                }
            }
        }
         return ans;   
    }
};