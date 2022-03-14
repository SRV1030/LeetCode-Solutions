// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
public:
    double angleClock(int h, int m) {
        double hr=(30*h+0.5*m),mn=6*m;
        double t=abs(hr-mn);
        return t>180?360-t:t;        
    }
};