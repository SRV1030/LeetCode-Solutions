// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int>mp;
        for(auto&i:s)mp[i]++;
        int mx=mp.size(),res=0;
        for(int uc=1;uc<=mx;uc++){
            int ws=0,we=0,idx=0,un=0,cK=0;
            mp.clear();
            while(we<s.size()){
                if(un<=uc){
                    if(!mp.count(s[we]))un++;
                    mp[s[we]]++;
                    if(mp[s[we]]==k)cK++;
                    we++;
                }else{
                    if(mp[s[ws]]==k)cK--;
                    mp[s[ws]]--;
                    if(mp[s[ws]]==0)un--;
                    ws++;
                }
                if(un==uc && un==cK)res=max(res,we-ws);
            }
        }
        return res;
    }
};