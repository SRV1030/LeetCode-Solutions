class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int c=0,ns=s.size();
        for(auto&i:words){
            int ni=i.size();
            if(ni>ns)continue;
            if(s.substr(0,ni)==i)c++;
        }
        return c;
    }
};