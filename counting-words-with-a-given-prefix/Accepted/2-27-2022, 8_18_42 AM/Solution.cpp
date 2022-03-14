// https://leetcode.com/problems/counting-words-with-a-given-prefix

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0,n=pref.size();
        for(auto&s:words)
            if(s.substr(0,n)==pref) c++;
        return c;
    }
};