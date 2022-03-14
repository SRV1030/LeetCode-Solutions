// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int>mp;
        for(auto i:r)mp[i]++;
        for(auto i:m){
            mp[i]--;
            if(mp[i]<0) return false;
        }
        return true;
        
    }
};