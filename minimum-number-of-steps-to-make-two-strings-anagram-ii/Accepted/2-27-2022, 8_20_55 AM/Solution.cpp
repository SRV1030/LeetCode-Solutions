// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>c1(26),c2(26);
        for(auto c:s)c1[c-'a']++;
        for(auto c:t)c2[c-'a']++;
        int c=0;
        for(int i=0;i<26;i++){
            c+=abs(c1[i]-c2[i]);
        }
        return c;
    }
};