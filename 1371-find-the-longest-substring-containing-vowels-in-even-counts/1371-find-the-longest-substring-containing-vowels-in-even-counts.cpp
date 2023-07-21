class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int mask=0,mx=0;
        string v="aeiou";
        for(int i=0;i<size(s);++i){
            mask^=(1<<(v.find(s[i])+1))>>1;
            if(!mp.count(mask))mp[mask]=i;
            mx=max(mx,i-mp[mask]);
        }
        return mx;
    }
};