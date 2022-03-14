// https://leetcode.com/problems/consecutive-numbers-sum

class Solution {
public:
    int consecutiveNumbersSum(int s) {
        int c=0,n=1;
        while((2*s+n-n*n)>0){
            double a=(2*s+n-n*n)/(2.0*n);
            if((long long int) a -a ==0)c++;
            n++;
        }
        return c;
    }
};