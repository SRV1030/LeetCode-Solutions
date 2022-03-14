// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        int a=0,b=1,c=1,z;
        for(int i=3;i<=n;i++){
            z=a+b+c;
            a=b;
            b=c;
            c=z;
        }
        return z;
    }
};