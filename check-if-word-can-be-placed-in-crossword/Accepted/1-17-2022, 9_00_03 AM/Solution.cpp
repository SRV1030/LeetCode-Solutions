// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword

class Solution {
public:
    int dir[4][2]={ { 0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int r,c;
    bool check(vector<vector<char>>& board,string word,int d,int i,int j){
        int pr=i-dir[d][0],pc=j-dir[d][1];
        if(pr>=0 && pr<r && pc>=0 && pc<c && board[pr][pc]!='#') return false;
        for(int ind=0;ind<word.size();ind++){
            if(i<0 || i>=r || j<0 || j>=c ) return false;
            else {
                if(board[i][j]==' '|| board[i][j]==word[ind]){
                    i+=dir[d][0];
                    j+=dir[d][1];
                }
                else return false;
            }
        }
        if(i>=0 && i<r && j>=0 && j<c)return board[i][j]=='#';
        return true;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        r=board.size(),c=board[0].size();                   
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int d=0;d<4;d++){                    
                    if(check(board,word,d,i,j))return true;
                }
            }
        }           
        return false;
        
        
    }
};