// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string g) {
        int ns=s.size(),ng=g.size();
        if(ns!=ng)return false;
        int i=0;
        for(;i<ns;i++)if(s[i]==g[0]) break;
        if(i==ns) return false;
        for(auto j:g){
            if(s[i]!=j)return false;
            i=(i+1)%ns;
        }
        return true;
    }
};