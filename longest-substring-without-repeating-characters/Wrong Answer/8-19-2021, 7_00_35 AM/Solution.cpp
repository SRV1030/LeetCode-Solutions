// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=1,b=0,i;
        unordered_map<char,int>mp;
        for(i=0;i<s.length();i++){
            if(mp.count(s[i])){
                mx=max(mx,i-b);
                b=max(b,mp[s[i]]+1);
                mp[s[i]]=i;
            }
            else mp[s[i]]=i;            
        }
        return mx;
    }
};