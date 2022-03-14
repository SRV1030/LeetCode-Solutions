// https://leetcode.com/problems/can-i-win

class Solution {
public: int m,t;
        vector<int>v;
    bool game(int mask,int score){
        if(v[mask]!=-1)return v[mask];
        for(int i=0;i<m;i++){
            int cmask=1<<i;
            if((mask&cmask)==0)
                if(score+i+1 >= t or game((mask|cmask),score+i+1)==false ) return v[mask]=1;
        }
        return v[mask]=0;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        m=maxChoosableInteger;t=desiredTotal;
        if((m*(m+1))/2<t)return false;
        v.resize(1<<m,-1);
        return game(0,0);    
    }
};