class Solution {
public:
    int commonFactors(int a, int b) {
        int c=1,mx=__gcd(a,b);
        for(int i=2;i<=mx;++i)c+=(a%i==0)&&(b%i==0);
        return c;
    }
};