// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    bool findRotation(vector<vector<int>>& m, vector<vector<int>>& t) {
        bool c[4];
        memset(c,true,sizeof(c));
        int n=m.size();
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m.size();j++){
                if(m[i][j]!=t[i][j]) c[0]=false;
                if(m[n-i-1][n-j-1]!=t[i][j]) c[1]=false;
                if(m[j][n-i-1]!=t[i][j]) c[2]=false;
                if(m[n-j-1][i]!=t[i][j]) c[3]=false;
            }
        }        
        return c[0]||c[1]||c[2]||c[3];
    }
};