// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length()) return 0;
        unordered_map<char,int>mp;
        mp[s[0]]=0;
        int b=0,mx=1,i;
        for( i=1;i<s.size();i++){
            if(mp.count(s[i])){
                mx=max(i-b,mx);
                b=mp[s[i]]+1;
                mp[s[i]]=i;
            }
            else mp[s[i]]=i;
        }
        return max(i-b,mx);
    }
};