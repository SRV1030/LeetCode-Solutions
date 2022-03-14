// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        long long int l=1, h=num/2;
        while(l<=h){
            long long int m=l+(h-l)/2,s=m*m;
            if(s==num) return true;
            if(s<num)l=m+1;
            else h=m-1;            
        }
        return false;
    }
};