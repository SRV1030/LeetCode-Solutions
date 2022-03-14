// https://leetcode.com/problems/nth-magical-number

class Solution {
public:
    int md=1e9+7;
    long long int lcm(int a,int b){
        return a*b/__gcd(a,b);
    }
    int nthMagicalNumber(int n, int a, int b) {
        int l=0,h=n*min(a,b),lc=lcm(a,b);
        while(l<h){
            int m=l+(h-l)/2;
            if(m/a+m/b-m/lc<n)l=m+1;
            else h=m;
        }
        return h%md;
        
    }
};