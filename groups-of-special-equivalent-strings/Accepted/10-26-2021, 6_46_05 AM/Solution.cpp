// https://leetcode.com/problems/groups-of-special-equivalent-strings

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto& i:words){            
            vector<char>e(26),o(26);
            for(int j=0;j<i.size();j++){
                if(j%2)o[i[j]-'a']++;
                else e[i[j]-'a']++;
            }
            string s;
            for(int j=0;j<26;j++){
                if(o[j]) s+=to_string(o[j])+(char)(j+'a')+'o';
                if(e[j]) s+=to_string(e[j])+(char)(j+'a')+'e';
            }             
            mp[s]++;
        }
        return mp.size();
    }
};