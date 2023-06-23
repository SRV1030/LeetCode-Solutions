class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        for(auto &j:t){
            if(s[i]==j)i++;
            if(i==s.size()) return true;
        }
        return i==s.size();
    }
};