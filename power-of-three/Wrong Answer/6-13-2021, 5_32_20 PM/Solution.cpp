// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        return ceil(log(n)/log(3))==floor(log(n)/log(3));
    }
};