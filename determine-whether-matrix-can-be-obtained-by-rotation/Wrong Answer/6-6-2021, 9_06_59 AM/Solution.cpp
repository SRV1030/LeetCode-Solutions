// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    bool findRotation(vector<vector<int>>& m, vector<vector<int>>& t) {
        int z1=0,z2=0;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m.size();j++){
                if(m[i][j]==0) z1++;
                if(t[i][j]==0) z2++;
            }
        }        
        return z1==z2;
    }
};