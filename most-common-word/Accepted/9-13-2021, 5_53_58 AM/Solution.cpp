// https://leetcode.com/problems/most-common-word

class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        set<string>st(banned.begin(),banned.end());
        unordered_map<string,int>mp;
        string t="";
        for(auto& i:p){
            if(isalpha(i)) t+=tolower(i);
            else{
                if(!t.empty())mp[t]++;
                t="";
            }
        }
        if(!t.empty())mp[t]++;
        string ans;
        int mx=0;
        for(auto i:mp)
            if(!st.count(i.first) && i.second>mx){
                mx=i.second;
                ans=i.first;
            }
        return ans;
    }
};