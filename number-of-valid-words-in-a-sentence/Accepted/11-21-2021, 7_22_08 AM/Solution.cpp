// https://leetcode.com/problems/number-of-valid-words-in-a-sentence

class Solution {
public:
    bool isValid(string s){
        int h=0;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) continue;
            if(isdigit(s[i])) return false;
            if((s[i]=='!'|| s[i]==',' || s[i]=='.')and i != s.size()-1) return false;
            if (s[i] == '-') {
                if (h || i == 0 || !isalpha(s[i-1]) || i == s.size()-1 || !isalpha(s[i+1])) return false;
                h++;
            }
        }
        return true;
    }
    int countValidWords(string sentence) {
        stringstream ss;
        ss<<sentence;
        string s;
        int c=0;
        while(ss>>s)if(isValid(s))c++;
        return c;
    }
};