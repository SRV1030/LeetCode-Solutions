// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int fr1[256]={0},fr2[256]={0};
        for(int i=0;i<s.size();i++){
            if(fr1[s[i]]!=fr2[t[i]]) return false;
            fr1[s[i]]++;
            fr2[t[i]]++;
        }
        return true;
    }
};