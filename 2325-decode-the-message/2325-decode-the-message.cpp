class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        char x='a';
        for(int i=0;i<size(key);++i){
            if(mp.count(key[i])||key[i]==' ')continue;
            mp[key[i]]=x++;
            if(x>'z') break;
        }
        string ans;
        for(auto&i:message)ans+=(i==' '?i:mp[i]);
        return ans;
    }
};