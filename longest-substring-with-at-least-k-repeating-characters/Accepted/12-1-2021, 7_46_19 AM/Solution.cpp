// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int>cmp;
        for(auto&i:s)cmp[i]++;
        int mx=cmp.size(),res=0;
        for(int uc=1;uc<=mx;uc++){
            int ws=0,we=0,idx=0,un=0,cK=0;
           vector<int>mp(26);
            while(we<s.size()){
                if(un<=uc){
                    idx=s[we]-'a';
                    if(mp[idx]==0)un++;
                    mp[idx]++;
                    if(mp[idx]==k)cK++;
                    we++;
                }else{
                    idx=s[ws]-'a';
                    if(mp[idx]==k)cK--;
                    mp[idx]--;
                    if(mp[idx]==0)un--;
                    ws++;
                }
                if(un==uc && un==cK)res=max(res,we-ws);
            }
        }
        return res;
    }
};