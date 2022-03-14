// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length()) return 0;
        unordered_map<char,int>mp;
        mp[s[0]]++;
        int c=1,mx=1;
        for(int i=1;i<s.size();i++){
            if(mp.count(s[i])){
                mx=max(c,mx);
                c=1;
                mp.clear();
                mp[s[i]]++;
            }
            else{
                c++;
                mp[s[i]]++;
            }
        }
        return max(c,mx);
    }
};