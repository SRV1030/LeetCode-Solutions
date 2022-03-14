// https://leetcode.com/problems/nth-digit

class Solution {
public:
    int findNthDigit(int n) {
        int l=1,c=9,st=1;
        while(n>(l*c)){
            n-=l*c;
            l++;
            c*=10;
            st*=10;
        }
        int d=n/l ,r=n%l;
        // cout<<st<<" "<<d<<" "<<r<<" ";
        if(!r) return (st+d-1)%10;
        else{
            int p=pow(10,r);
            return ((st+d)/p)%p;
        }
        return -1;
    }
};