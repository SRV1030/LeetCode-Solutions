// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       if(n<1) return 1;
       if(!isBadVersion(n)) return n+1;
       return firstBadVersion(n-1);
    }
};