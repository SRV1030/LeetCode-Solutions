// https://leetcode.com/problems/fibonacci-number

class Solution {
public: int f[31]={0};
    int fib(int n) {
        if(n<=2) return f[n]=1;
        if(f[n]!=0)return f[n];
        if(n%2==0){
            int k=n/2;
            f[k]=fib(k);
            f[k-1]=fib(k-1);
            f[n]=f[k]*(2*f[k-1]+f[k]);
        }
        else {
            int k=(n+1)/2;            
            f[k]=fib(k);
            f[k-1]=fib(k-1);
            f[n]=f[k]*f[k]+f[k-1]*f[k-1];
        }
        return f[n];
    }
};