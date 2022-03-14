// https://leetcode.com/problems/valid-tic-tac-toe-state

class Solution {
public:
    bool validTicTacToe(vector<string>& b) {
        vector<int>d(2),rd(2),t(2);
        vector<vector<int>> r(2,vector<int>(3)),c(2,vector<int>(3));
        vector<bool> w(2,false);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(b[i][j]==' ') continue;
                int x=b[i][j]=='X'?0:1;
                t[x]++;
                r[x][i]++;
                c[x][j]++;
                if(i==j)d[x]++;
                if(i==2-j)rd[x]++;
                if(r[x][i]==3 || c[x][j]==3 || d[x]==3 || rd[x]==3) w[x]=true;
            }
        }
        if((w[0] && w[1]) || (w[0] && t[0]-t[1]!=1) || (w[1] && t[0]-t[1]!=0) || t[1]-t[0]>0 || t[0]-t[1]>1 ) return false;      
        return true;
    }
};