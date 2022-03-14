// https://leetcode.com/problems/sudoku-solver

class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int i,int j,char c){
        for(int x=0;x<9;x++)
            if(board[i][x]==c || board[x][j]==c || board[(i/3)*3+x/3][(j/3)*3+x%3]==c) return false;
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};