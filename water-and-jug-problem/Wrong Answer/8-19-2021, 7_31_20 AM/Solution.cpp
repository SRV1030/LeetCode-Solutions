// https://leetcode.com/problems/water-and-jug-problem

class Solution {
public:
    bool canMeasureWater(int j1, int j2, int t) {
        return t%__gcd(j1,j2)==0;        
    }
};