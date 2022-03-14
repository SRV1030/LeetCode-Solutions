// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2 || n==3) return n;
        int a=2,b=3,c=3;
        for(int i=4;i<=n;i++ ){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};