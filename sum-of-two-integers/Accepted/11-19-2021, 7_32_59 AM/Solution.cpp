// https://leetcode.com/problems/sum-of-two-integers

class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int c=a&b;
            a^=b;
            b=(unsigned int)c<<1;
        }
        return a;
    }
};