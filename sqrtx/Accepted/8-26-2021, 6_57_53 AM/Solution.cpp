// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)return x;
        int l=1,h=x/2;
        while(l<=h){
            int m=l+(h-l)/2,q=x/m;
            if(m==q) return m;
            else if(m<q) l=m+1;
            else h=m-1;
        }
        return h;
    }
};