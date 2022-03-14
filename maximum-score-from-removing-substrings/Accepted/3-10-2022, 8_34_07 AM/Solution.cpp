// https://leetcode.com/problems/maximum-score-from-removing-substrings

class Solution {    
public:
    int rem(string &s, char a,char b, int x) {
        int i = 0, ans = 0;
        for (auto&ch:s) {
            s[i++] = ch;
            if (i > 1 && s[i - 2] == a && s[i - 1] ==b) i -= 2, ans += x; 
        }
        s.resize(i);
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        char a='a',b='b';
        if (x < y) swap(a, b), swap(x, y);
        return rem(s, a,b, x) + rem(s, b,a, y);
    }
};