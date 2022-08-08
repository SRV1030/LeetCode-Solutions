class Solution {
public:
    int balancedStringSplit(string s) {
        int f=0,c=0;
        for(auto&i:s){
            if(i=='R')++f;
            else --f;
            if(!f)++c;
        }
        return c;
    }
};