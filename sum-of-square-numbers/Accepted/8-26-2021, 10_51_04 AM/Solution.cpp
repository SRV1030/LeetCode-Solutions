// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l=0,h=sqrt(c);
        while(l<=h){
            long long s=l*l+h*h;
            if(s==c) return true;
            if(s>c)h--;
            else l++;
        }
        return false;
    }
};