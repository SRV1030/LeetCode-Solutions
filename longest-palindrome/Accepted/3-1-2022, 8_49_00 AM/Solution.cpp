// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(256,0);
        for(int i = 0; i < s.size(); ++i)
           ++v[s[i]];
        int res = 0;
        bool odd = false;
        for(int i = 0; i < 256; ++i)
           if(v[i]%2 == 0)
               res += v[i];
            else
            {
               res += v[i] - 1;
               odd = true;
            }
        if(odd)
          ++res;
        return res;
    }
};