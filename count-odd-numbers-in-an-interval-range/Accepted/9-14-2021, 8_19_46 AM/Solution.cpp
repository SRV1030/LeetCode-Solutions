// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int countOdds(int l, int h) {
        if(l==0) return h/2+h%2;
        l--;
        return h/2+h%2-l/2-l%2;
    }
};