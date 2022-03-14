// https://leetcode.com/problems/count-integers-with-even-digit-sum

class Solution {
public:
    int countEven(int num) {
        int dgs=0,n=num;
        while(n){
            dgs+=(n%10);
            n/=10;
        }
        if(num%2==0 && dgs&1) return num/2-1;
        return num/2;
    }
};