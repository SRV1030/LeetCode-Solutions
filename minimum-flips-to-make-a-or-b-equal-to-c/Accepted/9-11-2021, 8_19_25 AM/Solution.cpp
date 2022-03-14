// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ct=0;
        while(a||b||c){
            int ba=a&1,bb=b&1,bc=c&1;
            if((ba|bb)!=bc){
                if(ba && bb) ct+=2;
                else ct++;
            }
            a>>=1;b>>=1;c>>=1;
        }
        return ct;
    }
};