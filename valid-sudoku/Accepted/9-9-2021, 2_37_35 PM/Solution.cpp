// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>r(9),c(9),block(9);
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
               if(board[i][j]=='.') continue;
               if(r[i].count(board[i][j]) ||  c[j].count(board[i][j]) || block[i/3*3+j/3].count(board[i][j]))return false;
               r[i].insert(board[i][j]);
               c[j].insert(board[i][j]);
               block[i/3*3+j/3].insert(board[i][j]);
            }
        return true;
    }
};