//Backtrack and check for all possible positins of queem
//Check only for same row, top-left daigonal[r+c],top-rght diagonal[n-1+c-r]. Use hashin
class Solution {
public:
    vector<int>lr,ud,ld;
    vector<vector<int>>b;
    int r,ans=0;
    void solve(int j){
        if(j==r){
            ans++;
            return;
        }
        for(int i=0;i<r;++i){
            if(!lr[i] && !ud[i+j] && !ld[r-1+j-i]){
                lr[i]=ud[i+j]=ld[r-1+j-i]=1;
                b[i][j]=1;
                solve(j+1);
                lr[i]=ud[i+j]=ld[r-1+j-i]=0;
                b[i][j]=0;
            }
        }
    }
    int totalNQueens(int n) {
        r=n;
        lr=vector<int>(n);
        ud=ld=vector<int>(2*n);
        b.resize(n,vector<int>(n));
        solve(0);
        return ans;
    }
};