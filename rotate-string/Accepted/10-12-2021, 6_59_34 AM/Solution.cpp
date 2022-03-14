// https://leetcode.com/problems/rotate-string

class Solution {
public:
    string sft(string s,int a){
        return s.substr(a)+s.substr(0,a);
    }
    bool rotateString(string s, string goal) {
        int ns=s.size(),ng=goal.size();
        if(ns!=ng)return false;
        for(int i=0;i<ng;i++)
            if(goal[i]==s[0] && (s==sft(goal,i))) return true;
        return false;
    }
};