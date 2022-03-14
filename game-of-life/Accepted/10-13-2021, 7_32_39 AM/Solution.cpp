// https://leetcode.com/problems/game-of-life

class Solution {
public:
    int r,c;
    int getl(vector<vector<int>>& board,int i,int j){
        int l=0;
        if(i+1<r && board[i+1][j])l++;
        if(i+1<r && j+1<c && board[i+1][j+1])l++;
        if(j+1<c && board[i][j+1])l++;
        if(i-1>=0 && board[i-1][j])l++;
        if(i-1>=0 && j-1>=0 && board[i-1][j-1])l++;
        if(j-1>=0 && board[i][j-1])l++;
        if(i+1<r && j-1>=0 && board[i+1][j-1])l++;
        if(i-1>=0 && j+1<c && board[i-1][j+1])l++;
        return l;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>t(board);
        r=board.size();c=board[0].size();
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(board[i][j]){
                    int l=getl(board,i,j);
                    t[i][j]=(l==2 || l==3)?1:0;
                }
                else{
                    int l=getl(board,i,j);
                    t[i][j]= l==3?1:0;
                }
            }
        board=t;
        return;
    }
};