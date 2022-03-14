// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>=sx && ty>=sy){
            if(sx==tx && sy==ty) return true;
            if(tx>ty) tx%=ty;
            else ty%=tx;
            if(tx==sx){
                if((ty-sy)%sx==0) return true;
                return false;
            }
            if(ty==sy){
                if((tx-sx)%sy==0) return true;
                return false;
            }
        }
        return false;
    }
};