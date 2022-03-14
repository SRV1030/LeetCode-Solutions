// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements

class Solution {
public: long long int p=1e9+7;
    long long int power(long long int x,long long int y){
    long long int res = 1; 
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res%p;
}
    long long int minNonZeroProduct(int pd) {
        if(pd==1) return 1;
        long long int lm=power(2,pd)-1;
        // cout<<lm<<" ";
        long long int val=(lm-1)/2;
        // cout<<power(lm-1,val)<<" ";
        long long int res=((power(lm-1,val)%p)*(lm%p))%p;
        return res%p;
    }
};