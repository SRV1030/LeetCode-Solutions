// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int>mp;
        for(auto i:r)mp[i]++;
        for(auto i:m){
            if(mp.count(i))mp[i]--;
        }
        for(auto i:mp)if(i.second!=0) return false;
        return true;
        
    }
};