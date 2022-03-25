class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string,unordered_map<string,int>>mp;
        for(auto&i:items){
            mp["type"][i[0]]++;
            mp["color"][i[1]]++;
            mp["name"][i[2]]++;
        }
        return mp[ruleKey][ruleValue];
    }
};