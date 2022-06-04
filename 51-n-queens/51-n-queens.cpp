class Solution {
public: 
    vector<vector<string>> v;
    void solve(int &n,int c,vector<string> &board,vector<int>&lch,vector<int>&ud,vector<int>&ld){
        if(c==n){
            v.push_back(board);
            return;
        }
        for(int r=0;r<n;r++){
            if(!lch[r] && !ud[r+c] && !ld[n-1+c-r]){
                lch[r]=1;
                ud[r+c]=1;
                ld[n-1+c-r]=1;
                board[r][c]='Q';
                solve(n,c+1,board,lch,ud,ld);
                lch[r]=0;
                ud[r+c]=0;
                ld[n-1+c-r]=0;
                board[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int &n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)board[i]=s;
        vector<int>lch(n),ud(2*n),ld(2*n);
        solve(n,0,board,lch,ud,ld);
        return v;
    }
};