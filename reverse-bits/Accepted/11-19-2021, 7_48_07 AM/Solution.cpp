// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0,i=32;
        while(i--){
            ans<<=1;
            ans=ans|(n&1);
            n>>=1;
        }
        return ans;
    }
};