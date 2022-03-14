// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x > 0 && x % 10 == 0))
            return false;
        int tmp = 0;
        while(tmp < x && tmp < x / 10) {
            tmp *= 10;
            tmp += x % 10;
            x /= 10;
        }
        return tmp == x || tmp == x/10;
    }
};