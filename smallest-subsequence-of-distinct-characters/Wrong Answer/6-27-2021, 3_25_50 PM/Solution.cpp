// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters

class Solution {
public:
    string smallestSubsequence(string s) {
       set<char>s1(s.begin(),s.end());
        string ans(s1.begin(),s1.end());
        return ans;
    }
};