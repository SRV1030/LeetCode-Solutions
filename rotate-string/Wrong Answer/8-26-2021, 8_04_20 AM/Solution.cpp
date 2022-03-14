// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        int ns=s.size(),ng=goal.size();
        if(ns!=ng)return false;
        size_t f=goal.find(s[0]);
        if(f==string::npos) return false;
        f=(f+1)%ng;
        for(int i=1;i<ns;i++){
            if(s[i]!=goal[f]) return false;
            f=(f+1)%ng;
        }
        return true;
    }
};