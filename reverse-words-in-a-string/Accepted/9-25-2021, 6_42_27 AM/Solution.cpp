// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        string t="";
        int i=s.size()-1,j=i;
        while(i>=0){
            while(i>=0 && s[i]==' ')i--;
            if(i<=-1) break;
            j=i;
            while(i>=0 && s[i]!=' ')i--;
            t+=s.substr(i+1,j-i)+" ";            
        }
        return t.substr(0,t.length()-1);
    }
};