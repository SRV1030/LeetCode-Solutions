// https://leetcode.com/problems/count-good-numbers

class Solution {
public: long long int p=1000000007;
   unsigned long long int power(unsigned long long int x, unsigned long long int y){  
    unsigned long long int res = 1;  
    x = x % p;
    if (x == 0) return 0; 
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}
    int countGoodNumbers(long long n) {
        if(n==1) return 5;
        unsigned long long int a=n/2;
        return power(5,n-a)*power(4,a)%p;
        
    }
};