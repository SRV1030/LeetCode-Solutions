// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        int c=0,xr=x^y;
        while(xr){
            xr=xr&(xr-1);
            c++;
        }
        return c;
    }
};