// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nn=needle.length(),nh=haystack.length();
        if((!nn && nh) || nn>nh) return -1;
        for(int i=0;i<nh-nn+1;i++)
            if(haystack.substr(i,nn)==needle) return i;
        return -1;
    }
};