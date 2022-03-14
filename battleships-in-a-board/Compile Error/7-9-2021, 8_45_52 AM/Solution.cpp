// https://leetcode.com/problems/battleships-in-a-board

class Solution {
public: int n,m;
    void dfs(vector<vector<char>>& b,int i,int j){
        if(i<0 || j<0 || i>=n || j>=b[0].size() ||b[i][j]!='X') return;
        b[i][j]='$';
        dfs(b,i+1,j);
        dfs(b,i-1,j);
        dfs(b,i,j+1);
        dfs(b,i,j-1);        
        
    }
    int countBattleships(vector<vector<char>>& board) {
        int c=0;
        n=b.size(),m=b[0].size();
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]=='X'){
                    dfs(board,i,j);
                    c++;
                }
        return c;
    }
};