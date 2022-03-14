// https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent

class Solution {
public:
    bool checkAlmostEquivalent(string w1, string w2) {
        vector<int> v1(26),v2(26);
        for(int i=0,j=0;i<w1.size()|| j<w2.size();i++,j++){
            if(i<w1.size())v1[w1[i]-'a']++;
            if(j<w2.size())v2[w2[j]-'a']++;
        }
        for(int i=0;i<26;i++)
            if(abs(v1[i]-v2[i])>3) return false;
        return true;        
    }
};