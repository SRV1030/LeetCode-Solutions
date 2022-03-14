// https://leetcode.com/problems/check-if-move-is-legal

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        vector<vector<int>> DIRS = {{0 , -1} , {0 , +1} , {-1 , 0} , {+1 , 0} , {-1,-1} , {+1,+1} , {-1,+1} , {+1,-1}};
        for(auto dir : DIRS){
            int i = rMove + dir[0];
            int j = cMove + dir[1];
            int leng = 1;
            bool flag = false; 
            while(i >= 0 and i < board.size() and j >= 0 and j < board.size()){
                if(board[i][j] == color){
                    ++leng;
                    flag = true;
                    break;
                }
                else if(board[i][j] == '.') break;
                ++leng;
                i += dir[0];
                j += dir[1];
            }
            if(flag and leng >= 3) return true;
        }
        return false;
    }
};