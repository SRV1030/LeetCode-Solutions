class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        int r=size(g),c=size(g[0]);
        k=k%(r*c);
        vector<vector<int>>ans(r,vector<int>(c));
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                int nj=(j+k)%c,ni=(i+(j+k)/c)%r;
                ans[ni][nj]=g[i][j];
            }
        }
        return ans;
    }
};