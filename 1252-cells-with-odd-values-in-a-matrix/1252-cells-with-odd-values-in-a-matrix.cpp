class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int>r(m),c(n);
        for(auto&i:indices)r[i[0]]=!r[i[0]],c[i[1]]=!c[i[1]];
        int ans=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)ans+=r[i]^c[j];
        return ans;
    }
};