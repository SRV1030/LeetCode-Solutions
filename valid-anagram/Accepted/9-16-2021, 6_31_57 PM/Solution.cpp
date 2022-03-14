// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int>a(26);
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        for(auto&i:a)if(i) return false;
        return true;
    }
};