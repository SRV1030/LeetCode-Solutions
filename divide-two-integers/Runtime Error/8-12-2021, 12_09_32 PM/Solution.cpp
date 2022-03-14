// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1) return dividend;
        if((divisor==-1 && dividend==(1<<31)))return INT_MAX;
        if(dividend==0)return 0;
        int ans=0;
        bool s=(dividend<=0)==(divisor<=0);
        dividend=abs(dividend);
        divisor=abs(divisor);
        while(dividend>=divisor){
            int c=1,t=divisor;
            while((t<<1)<=dividend){
                t<<=1;
                c<<=1;
            }
            ans+=c;
            dividend-=t;
        }
        return s?ans:-ans;
    }
};