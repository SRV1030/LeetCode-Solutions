class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> st[26];        
        long long c=0,cnt[26][26]={};
        for(auto&i:ideas)st[i[0]-'a'].insert(i.substr(1));
        for(int i=0;i<26;++i)
            for(auto&suf:st[i])
                for(int j=0;j<26;++j)
                    cnt[i][j]+=st[j].count(suf)==0;
        for(int i=0;i<26;++i)
            for(int j=0;j<26;++j)c+=cnt[i][j]*cnt[j][i];
        return c;
    }
};