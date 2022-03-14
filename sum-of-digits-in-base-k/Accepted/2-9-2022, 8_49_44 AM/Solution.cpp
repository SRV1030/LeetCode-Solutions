// https://leetcode.com/problems/sum-of-digits-in-base-k

class Solution {
public:
    int sumBase(int n, int k) {
        int rem=0;
        while(n){
            rem+=(n%k);
            n/=k;
        }
        return rem;
    }
};