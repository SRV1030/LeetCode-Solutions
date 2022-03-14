// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int c=0;
        while(n/5>=1){
            c+=n/5;
            n/=5;
        }
        return c;
    }
};