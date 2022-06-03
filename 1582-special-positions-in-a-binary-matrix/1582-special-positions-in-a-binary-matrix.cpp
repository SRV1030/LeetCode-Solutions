class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r=mat.size(),c=mat[0].size(),ans=0;
        vector<int>rv(r),cv(c);
        vector<vector<int>>pr;
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                if(mat[i][j]){
                    pr.push_back({i,j});
                    rv[i]++;
                    cv[j]++;
                }
        for(auto&i:pr)
            if(rv[i[0]]==1 && cv[i[1]]==1)++ans;
        return ans;
    }
};