// https://leetcode.com/problems/minimum-moves-to-convert-string

class Solution {
public:
    int minimumMoves(string s) {
        int x=0,c=0,ans=0;
        for(auto& i:s){
            c++;
            if(i=='X')x++;
            if(c==3){
                if(x)ans++;
                x=0;c=0;
            }
        }
        return x?ans+1:ans;
    }
};