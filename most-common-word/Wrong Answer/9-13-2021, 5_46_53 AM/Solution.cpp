// https://leetcode.com/problems/most-common-word

class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        set<string>st(banned.begin(),banned.end());
        p[p.size()-1]=' ';
        p+='\n';
        stringstream s(p);
        unordered_map<string,int>mp;
        string val;
        getline(s,val,' ');
        while(val!="\n"){
            if(!isalpha(val[val.size()-1]))val.pop_back();
            transform(val.begin(), val.end(), val.begin(), ::tolower);
            mp[val]++;
            getline(s,val,' ');
        }
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