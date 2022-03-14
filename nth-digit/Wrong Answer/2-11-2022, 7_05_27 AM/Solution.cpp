// https://leetcode.com/problems/nth-digit

class Solution {
public:
    int findNthDigit(int n) {
        int l=1,c=9;
        while(n>(l*c)){
            n-=l*c;
            l++;
            c*=10;
        }
        int st=pow(10,l-1);
        int d=n/l ,r=n%l;
        if(!r) return (st+d-1)%10;
        else{
            int p=pow(10,r);
            return (st+d-1)%p;
        }
        return -1;
    }
};