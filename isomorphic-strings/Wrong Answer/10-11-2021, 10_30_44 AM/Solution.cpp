// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for(int i=0,j=0;i<s.size()-1&&j<t.size()-1;i++,j++)
            if( (s[i]==s[i+1] && t[j]!=t[j+1]) || (s[i]!=s[i+1] && t[j]==t[j+1]) ) return false;
        return true;
    }
};