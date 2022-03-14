// https://leetcode.com/problems/sentence-similarity-iii

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {        
        if(s1.size()==s2.size()) return s1==s2;
        vector<string>v1,v2;
        stringstream str1(s1),str2(s2);
        string w;
        while(str1>>w)v1.push_back(w);
        while(str2>>w)v2.push_back(w);
        if(v1.size()<v2.size()) swap(v1,v2);
        int i=0,j=v2.size()-1,diff=v1.size()-v2.size();
        while(i<v2.size() && v2[i]==v1[i]) ++i;
        while(j>=0 && v2[j]==v1[j+diff]) --j;
        return i>j;
    }
};