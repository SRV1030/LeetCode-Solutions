// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.size()-1,l=0;
        while(j>=0 && s[j]==' ')j--;
        while(j>=0 && s[j]!=' '){
            j--;
            l++;
        } 
        return l;
    }
};