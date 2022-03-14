// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string r=s.substr(0,10);
        unordered_map<string,int>mp;
        mp[r]++;
        for(int j=10;j<s.length();j++){
            r+=s[j];
            r=r.substr(1,10);
            mp[r]++;
        }
        vector<string> ans;
        for(auto i:mp){
            if(i.second>1)ans.push_back(i.first);
        }
        return ans;
        
    }
};