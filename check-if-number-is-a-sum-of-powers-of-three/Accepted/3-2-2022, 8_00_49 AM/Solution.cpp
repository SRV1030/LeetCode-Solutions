// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three

class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n==1) return true;
        if(n%3==2) return false;
        return checkPowersOfThree(n/3);
    }
};