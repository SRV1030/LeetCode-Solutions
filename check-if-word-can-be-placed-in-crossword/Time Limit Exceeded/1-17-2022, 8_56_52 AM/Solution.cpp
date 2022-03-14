// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword

class Solution {
public:
    vector<vector<int>>dir={ { 0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int r,c;
    bool check(vector<vector<char>>& board,string word,vector<int> d,int i,int j){
        int pr=i-d[0],pc=j-d[1];
        if(pr>=0 && pr<r && pc>=0 && pc<c && board[pr][pc]!='#') return false;
        for(int ind=0;ind<word.size();ind++){
            if(i<0 || i>=r || j<0 || j>=c ) return false;
            else {
                if(board[i][j]==' '|| board[i][j]==word[ind]){
                    i+=d[0];
                    j+=d[1];
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
                for(auto&d:dir){                    
                    if(check(board,word,d,i,j))return true;
                }
            }
        }           
        return false;
        
        
    }
};