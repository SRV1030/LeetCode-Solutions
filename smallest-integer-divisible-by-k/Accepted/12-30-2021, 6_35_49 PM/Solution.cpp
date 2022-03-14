// https://leetcode.com/problems/smallest-integer-divisible-by-k

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem=0;
        for(int i=1;i<=k;i++){
            rem=(rem*10+1)%k;
            if(rem==0) return i;
        }
        return -1;
    }
};