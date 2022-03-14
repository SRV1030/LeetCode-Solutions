// https://leetcode.com/problems/sum-of-two-integers

class Solution {
public:
    int getSum(int a, int b) {
        // a^b+(a&b)*2 sum
        while(b){
            int c=a&b;
            a^=b;
            b=(unsigned int)c<<1;
        }
        return a;
    }
};