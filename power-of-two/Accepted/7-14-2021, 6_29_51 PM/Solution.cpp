// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n%2 || n==0) return false;
        double x=ceil((double)log2(n));
         double y=floor((double)log2(n));
        return x==y;
    }
};