// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mp[]={1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0};
        int mask=0,mx=0;
        vector<int>comb(32,-1);//cz we have 2^5 comb of masks;
        for(int i=0;i<s.size();i++){
            mask^=mp[s[i]-'a'];
            if(mask>0 && comb[mask]==-1)comb[mask]=i;
            mx=max(mx,i-comb[mask]);
        }
        return mx;
    }
};