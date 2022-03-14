// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        map<char,int>mp;
        string ans;
        for(auto i:s)mp[i]++;
        for(auto i:mp)
            if(i.second%k){
                int x=i.second%k;
                while(x--)ans.push_back(i.first);
            }
        return ans;
    }
};