// https://leetcode.com/problems/word-pattern

class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char,string> mp;
        int j=0,i=0,np=p.size(),ns=s.size();
        while(i<np && j<ns){
            string t="";
            while(j<ns && s[j]!=' ')t+=s[j++];
            if(mp.count(p[i])){
                if(mp[p[i]]!=t) return false;
            } 
            else {
                for(auto x:mp)
                    if(x.second==t)return false;
                mp[p[i]]=t;
            }
            i++;
            j++;
        }
        return i==np && j==ns+1;
    }
};