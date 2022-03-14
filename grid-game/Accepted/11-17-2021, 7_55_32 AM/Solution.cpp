// https://leetcode.com/problems/grid-game

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long f=0,s=0,res=LONG_MAX;
        for(auto& i:grid[0])f+=i;
        for(int i=0;i<n;i++){
            f-=grid[0][i];
            res=min(res,max(f,s));
            s+=grid[1][i];
        }
        return res;
    }
};