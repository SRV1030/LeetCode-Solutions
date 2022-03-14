// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    int r,c;
    void solve(vector<vector<char>>& board) {
        r=board.size(),c=board[0].size();
        for(int i=0;i<r;i++){
            check(board,i,0);
            check(board,i,c-1);
        }
        for(int i=0;i<c;i++){
            check(board,0,i);
            check(board,r-1,i);
        }
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(board[i][j]=='O')board[i][j]='X';
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(board[i][j]=='E')board[i][j]='O';
        
    }
    void check(vector<vector<char>>& board,int i,int j){
        if(board[i][j]=='O'){
            board[i][j]='E';
            if(i+1<r)check(board,i+1,j);
            if(j+1<c)check(board,i,j+1);
            if(i-1>=0)check(board,i-1,j);
            if(j-1>=0)check(board,i,j-1);
        }
    }
};