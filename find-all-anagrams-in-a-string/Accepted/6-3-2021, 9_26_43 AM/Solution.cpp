// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    bool checkAnar(int ch[]){
        for(int i=0;i<26;i++)
            if(ch[i]!=0) return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) return{};
        vector<int> v;
        int ch[26];
        memset(ch,0,sizeof(ch));
        int n=s.size(),m=p.size();
        for(int i=0;i<m;i++){
            ch[s[i]-'a']++;
            ch[p[i]-'a']--;
        }
        if(checkAnar(ch))v.push_back(0);
        for(int i=1;i<n-m+1;i++){
            ch[s[i-1]-'a']--;
            ch[s[m+i-1]-'a']++;
            if(checkAnar(ch))v.push_back(i);            
        }
        return v;
    }
    
};