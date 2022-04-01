class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string>mp;
        for(auto&i:k)mp[i[0]]=i[1];
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                i++;
                string t;
                while(s[i]!=')')t+=s[i++];
                ans+=mp.count(t)?mp[t]:"?";
            }
            else ans+=s[i];
        }
        return ans;
    }
};