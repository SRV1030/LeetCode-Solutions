// https://leetcode.com/problems/uncommon-words-from-two-sentences

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        istringstream ss(s1);
        string word;
        while(ss>>word) ++mp[word];
        istringstream sss(s2);
        word="";
        while(sss>>word) ++mp[word];
        vector<string> ans;
        for(const auto &i:mp){
            if(i.second==1) ans.push_back(i.first);
        }
        return ans;
    }
};