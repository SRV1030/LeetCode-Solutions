// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0,p=31;
        while(n){
            res+=(n&1)<<p;
            p--;
            n>>1;
        }
        return res;
    }
};