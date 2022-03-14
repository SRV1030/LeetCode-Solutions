// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n<0)n*=(-1);
        double pw=(log10(n)/log10(3));
        return (int)ceil(pw)==(int)floor(pw);
    }
};