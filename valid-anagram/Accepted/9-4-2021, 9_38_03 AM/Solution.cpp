// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int>v(26);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        for(auto& i:v)if(i!=0) return false;
        return true;
    }
};