// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.00000;
        if(x==0) return 0.00000;
        double res=1;
        while(n>0){
            if(n%2) res*=x;
            n>>=1;
            x*=x;            
        }
        return res;
    }
};