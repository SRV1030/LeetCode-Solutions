// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements

class Solution {
public: long long p = 1000000007;
    long long power(long long x,long long y){
    long long res = 1; 
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0){
        if (y & 1)
            res*=x;
        y = y>>1; 
        x = x*x;
        x%=p;
        res%=p;
    }
    return res;
}
    int minNonZeroProduct(int pd) {
        if(pd==1) return 1;
        long long lm=(1L<<pd)-1;
        long long res=((power(lm-1,lm/2)%p)*(lm%p))%p;
        return res;
    }
};