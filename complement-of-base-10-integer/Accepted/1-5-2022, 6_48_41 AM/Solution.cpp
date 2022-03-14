// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        int m=n,msk=0;
        while(m){
            msk=(msk<<1)|1;
            m>>=1;
        }
        return ~n&msk;
    }
};