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
            long c=0;
            while(div-(dvs<<1<<c)>=0) c++;
            ans+=1<<c;
            div-=dvs<<c;
        }
        return s?ans:-ans;
    }
};