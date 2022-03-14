// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1) return dividend;
        if((divisor==-1 && dividend==(1<<31)))return INT_MAX;
        if(dividend==0)return 0;
        long ans=0;
        bool s=(dividend<=0)==(divisor<=0);
        long div=labs(dividend),dvs=labs(divisor);
        while(div>=dvs){
            long c=1,t=dvs;
            while((t<<1)<=div){
                t<<=1;
                c<<=1;
            }
            ans+=c;
            div-=t;
        }
        return s?ans:-ans;
    }
};