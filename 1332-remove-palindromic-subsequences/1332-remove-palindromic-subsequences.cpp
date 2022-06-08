class Solution {
public:
    int removePalindromeSub(string s) {
        return s.empty()?0:s==string(rbegin(s),rend(s))?1:2;
    }
};