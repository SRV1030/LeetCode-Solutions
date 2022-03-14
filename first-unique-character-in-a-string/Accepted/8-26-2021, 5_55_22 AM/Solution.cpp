// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>f(26);
        for(auto&i:s)f[i-'a']++;
        for(int i=0;i<s.size();i++)if(f[s[i]-'a']==1) return i;
        return -1;
    }
};