// https://leetcode.com/problems/sentence-similarity-iii

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()<s2.size()) return areSentencesSimilar(s2,s1);
        if(s1.size()==s2.size()) return s1==s2;
        // if(find(s1.begin(),s1.end(),s2)==s1.end()) return false;
        vector<string>v1,v2;
        stringstream str1(s1),str2(s2);
        string w;
        while(str1>>w)v1.push_back(w);
        while(str2>>w)v2.push_back(w);
        int i=0,j=0,f=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]==v2[j]) {
                i++;
                j++;
                if(f==1) f=2;
            } 
            else{
                i++;  
                if(f==2) return false;
                f=1;
            } 
            
        }
        if(i==v1.size() && j==v2.size()) return true;
        return f!=2;
    }
};