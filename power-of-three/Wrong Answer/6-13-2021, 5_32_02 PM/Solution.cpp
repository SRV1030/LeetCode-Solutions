// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        
        return ceil(log(n)/log(3))==floor(log(n)/log(3));
    }
};