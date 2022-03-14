// https://leetcode.com/problems/bulb-switcher-ii

class Solution {
public:
    int flipLights(int n, int p) {
        if(p==0) return 1;
        if(n==1) return 2;
        if(n==2) return p==1?3:4;
        else return p==1?4:p==2?7:8;
    }
};