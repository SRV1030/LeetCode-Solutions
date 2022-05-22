class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        bool oo=false;
        int r=mat.size(),c=mat[0].size();
        for(int i=0;i<r;i++){
            if(!mat[i][0])oo=true;
            for(int j=1;j<c;j++)
                if(!mat[i][j])mat[i][0]=mat[0][j]=0;
        }
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=1;j--)
                if(!mat[i][0] || !mat[0][j])mat[i][j]=0;
            if(oo)mat[i][0]=0;
        }    
    }
};