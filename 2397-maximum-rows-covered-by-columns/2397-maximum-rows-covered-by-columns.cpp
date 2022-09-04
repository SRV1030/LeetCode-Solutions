class Solution {
public:
    int res;
    void findres(vector<vector<int>>& mt,vector<int>&vt,int vl,int i){
        if(!vl){
            int cur=0;
            for(int i=0;i<mt.size();i++){
                int f=0;
                for(int j=0;j<mt[0].size();j++){
                    if(vt[j]==0&&mt[i][j]==1){
                        f=1;
                    }
                }
                if(!f)cur++;
            }
            res=max(res,cur);
        }
        if(i==mt[0].size())return;
        vt[i]=1;
        findres(mt,vt,vl-1,i+1);
        vt[i]=0;
        findres(mt,vt,vl,i+1);
    }
    int maximumRows(vector<vector<int>>& mt, int cols) {
        int n=mt.size();
        int m=mt[0].size();
        res=0;
        vector<int>vt(m);
        findres(mt,vt,cols,0);
        return res;
    }
};