// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        vector<int> mp1(26),mp2(26);
        int ns1=s1.size(),ns2=s2.size();
        for(auto& i:s1)mp1[i-'a']++;
        for(int i=0;i<ns2;i++){
           mp2[s2[i]-'a']++; 
           if(i>=ns1)mp2[s2[i-ns1]-'a']--; 
           if(mp1==mp2) return true;
        }
        return false;
    }
};