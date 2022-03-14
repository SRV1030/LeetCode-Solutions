// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string t;
        int k=s.size();
        for(auto&i:words){
            t+=i;
            if(t==s) return true;
        }
        return false;
    }
};