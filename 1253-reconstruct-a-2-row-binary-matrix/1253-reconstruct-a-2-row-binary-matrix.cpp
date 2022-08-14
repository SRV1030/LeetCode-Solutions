class Solution {
public:
    vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& cl) {
        vector<vector<int>> ans(2,vector<int>(size(cl)));
        for(int i=0;i<size(cl);u-=ans[0][i],l-=ans[1][i++]){
            ans[0][i]=cl[i]==2 || (cl[i]==1 && u>=l);
            ans[1][i]=cl[i]==2 || (cl[i]==1 && l>u);
        }
        return (u==0 && l==0)?ans:vector<vector<int>>();
    }
};