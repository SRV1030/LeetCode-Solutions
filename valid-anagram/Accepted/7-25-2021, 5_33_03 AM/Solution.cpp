// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>c(26);
        for(auto& i:s)c[i-'a']++;
        for(auto& i:t)c[i-'a']--;
        for(auto&i:c) if(i!=0) return false;
        return true;
    }
};