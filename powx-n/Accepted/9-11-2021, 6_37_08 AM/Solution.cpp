// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0.0;
        if(n==0) return 1.0;
        double res=1;
        if(n>0){
            while(n>0){
                if(n%2)res*=x;
                n/=2;
                x*=x;
            }
        }else{
            n=abs(n);
            while(n>0){
                if(n%2)res/=x;
                n/=2;
                x*=x;
            }
        }
        
        return res;
    }
};