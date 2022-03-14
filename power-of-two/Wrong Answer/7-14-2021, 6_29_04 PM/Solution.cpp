// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n%2) return false;
        double x=ceil((double)log2(n));
         double y=floor((double)log2(n));
        return x==y;
    }
};