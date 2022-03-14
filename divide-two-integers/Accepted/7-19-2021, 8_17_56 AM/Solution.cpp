// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==-1 && dividend==(1<<31))return INT_MAX;
        if(dividend==0)return 0;
        if(divisor<0){
            if(divisor==(1<<31)){
                return divisor==dividend;
            }
        }
        return dividend/divisor;
    }
};