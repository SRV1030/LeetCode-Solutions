class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int> ans;
        for(int i=0;i<mat.size();++i){
            int mn=INT_MAX,ind=-1;
            for(int j=0;j<mat[0].size();++j)
                if(mat[i][j]<mn){
                    mn=mat[i][j];
                    ind=j;
                }
            bool f=0;
            for(int x=0;x<size(mat);++x)
                if(mat[x][ind]>mn){f=1;break;}
            if(!f)ans.push_back(mn);
        }
        return ans; 
    }
};