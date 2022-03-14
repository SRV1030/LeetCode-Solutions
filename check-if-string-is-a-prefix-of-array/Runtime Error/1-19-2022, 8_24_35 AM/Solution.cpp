// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string t;
        int k=s.size();
        for(int i=0;i<k;i++){
            t+=words[i];
            if(t.size()>=k) return t==s;
        }
        return false;
    }
};