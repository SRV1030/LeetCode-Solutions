// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>mp;
        int n=words.size();
        for(auto i:words)
            for(auto j:i)mp[j]++;
        for(auto i:mp)
            if(i.second%n)return false;
        return true;
        
    }
};