// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_map<char,int>mp;
        mp[s[0]]=0;
        int b=0,i,mx=0;
        for(i=1;i<s.length();i++){
            if(mp.count(s[i])){
                mx=max(mx,i-b);
                b=max(b,mp[s[i]]+1);
                mp[s[i]]=i;
            }
            else mp[s[i]]=i;
        }
        return max(mx,i-b);
    }
};
