class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& g) {
        int nr=size(g),nc=size(g[0]);
        vector<vector<int>> ans(nr,vector<int>(nc));
        for(int i=0;i<nr;++i)
            for(int j=0;j<nc;++j){
                unordered_set<int>tl,br;
                int tx=i-1,ty=j-1,bx=i+1,by=j+1;
                while(tx>=0 && ty>=0)tl.insert(g[tx--][ty--]);
                while(bx<nr && by<nc)br.insert(g[bx++][by++]);
                ans[i][j]=abs((int)size(tl)-(int)size(br));
            
            }
        return ans;
    }
};