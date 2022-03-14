// https://leetcode.com/problems/battleships-in-a-board

class Solution {
public:
    void dfs(vector<vector<char>>& b,int i,int j){
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size() ||b[i][j]!='X') return;
        b[i][j]='$';
        dfs(b,i+1,j);
        dfs(b,i-1,j);
        dfs(b,i,j+1);
        dfs(b,i,j-1);        
        
    }
    int countBattleships(vector<vector<char>>& board) {
        int c=0;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]=='X'){
                    dfs(board,i,j);
                    c++;
                }
        return c;
    }
};