// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        if(word.size()<=n){            
            for(int i=0;i<m;i++){
                int c=0,ind=0;
                for(int j=0;j<n;j++){
                    if(board[i][j]==' '||(ind<word.size() && word[ind]==board[i][j])){
                        c++;
                        ind++;
                    }else{
                        c=0;
                        ind=0;
                    }
                }
                if(c==word.size())return true;
            }
            for(int i=m-1;i>=0;i--){
                int c=0,ind=0;
                for(int j=n-1;j>=0;j--){
                    if(board[i][j]==' '||(ind<word.size() && word[ind]==board[i][j])){
                        c++;
                        ind++;
                    }else{
                        c=0;
                        ind=0;
                    }
                }
                if(c==word.size())return true;
            }
        }
        if(word.size()<=m){            
            for(int j=0;j<n;j++){
                int c=0,ind=0;
                for(int i=0;i<m;i++){
                    if(board[i][j]==' '||(ind<word.size() && word[ind]==board[i][j])){
                        c++;
                        ind++;
                    }else{
                        c=0;
                        ind=0;
                    }
                }
                if(c==word.size())return true;
            }
            for(int j=n-1;j>=0;j--){
                int c=0,ind=0;
                for(int i=m-1;i>=0;i--){
                    if(board[i][j]==' '||(ind<word.size() && word[ind]==board[i][j])){
                        c++;
                        ind++;
                    }else{
                        c=0;
                        ind=0;
                    }
                }
                if(c==word.size())return true;
            }
        }
        return false;
        
        
    }
};