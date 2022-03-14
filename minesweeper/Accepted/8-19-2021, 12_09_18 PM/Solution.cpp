// https://leetcode.com/problems/minesweeper

class Solution {
public:
    int getAdjc(vector<vector<char>>& board,int x,int y){
        int mc=0;
        for(int i=x-1;i<=x+1;i++)
            for(int j=y-1;j<=y+1;j++)
                if(i>=0 && i<board.size() && j>=0 && j<board[0].size() && board[i][j]=='M')mc++;
        return mc;        
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int> &click) {
        int x=click[0],y=click[1];
        if(board[x][y]=='M')board[x][y]='X';
        else{
            int num=getAdjc(board,x,y) ;
            if(num) board[x][y]=num+'0';
            else{       
                board[x][y]='B';
                for(int i=x-1;i<=x+1;i++)
                    for(int j=y-1;j<=y+1;j++)
                        if(i>=0 && i<board.size() && j>=0 && j<board[0].size() && board[i][j]!='B')updateBoard(board,click={i,j});
            }
        }
        return board;
    }
};