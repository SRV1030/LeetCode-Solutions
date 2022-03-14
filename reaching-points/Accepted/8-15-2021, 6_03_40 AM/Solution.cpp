// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>=sx && ty>=sy){
            if(tx==sx && ty==sy) return true;
            if(tx>ty)tx%=ty;
            else ty%=tx;
            if(tx==sx){
                if((ty-sy)%sx==0) return true;
                else return false;
            }
            if(ty==sy){
                if((tx-sx)%sy==0) return true;
                else return false;
            }
        }
        return false;
    }
};
