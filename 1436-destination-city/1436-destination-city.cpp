class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>mp;
        for(auto&i:paths)mp.insert(i[0]);
        for(auto&i:paths)if(mp.insert(i[1]).second)return i[1];
        return "";
    }
};